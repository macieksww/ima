#!/usr/bin/env python
# license removed for brevity
from telnetlib import STATUS
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist
from math import pi, floor, atan2, sqrt, sin, cos
from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import *
from tf.transformations import euler_from_quaternion, quaternion_from_euler
from package_303770.msg import ranges
import actionlib
from actionlib_msgs.msg import GoalStatus
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
from math import sin, cos, atan2, pi

import datetime



class ScanServer:
    def __init__(self):

        self.scan_subscriber = rospy.Subscriber('/vacuum_sensors', ranges, self.subscriber_callback)
        self.nav_status_subscriber = rospy.Subscriber('/move_base/status', GoalStatus, self.nav_status_subscriber_callback)
        self.n = rospy.get_param("/sectors")
        self.destination = rospy.get_param("/destination")
        self.crds_dict = {}
        self.crds_dict['droom'] = ([3.0, 0.5], [7.0, 0.5], [7.0, 4.2], [3.0, 4.2])
        self.crds_dict['kitchen'] = ([5.5, -4.5], [6.5, -4.5], [5.5, -1.0], [6.5, -1.0])
        self.crds_dict['rubbish'] = ([1.75, 4.75], [1.75, 1.5], [0.5, 1.5], [0.5, 4.75])
        self.crds_dict['lroom'] = ([-0.5, 0.5], [-0.5, 4.75], [-4.75, -4.75], [-4.75, 0.5])
        self.crds_dict['office'] = ([-5.5, 4.5], [-5.5, 1.5], [-7.0, 1.5], [-7.0, 4.5])
        self.crds_dict['bath'] = ([-5.5, 0.5], [-5.5, -3.5], [-7.0, -3.5], [-7.0, 0.5])
        self.departure_time = datetime.datetime.now()
        self.prev_departure_time = datetime.datetime.now()
        self.elapsed_time = datetime.datetime.now()
        self.cannot_reach_local_goal = False
        self.visited_points = []

        self.clean()


    def subscriber_callback(self, data):

        self.header = data.header
        self.angle_min = data.angle_min
        self.angle_max = data.angle_max
        self.angle_increment = data.angle_increment
        self.time_increment = data.time_increment
        self.scan_time = data.scan_time
        self.range_min = data.range_min
        self.range_max = data.range_max
        self.ranges = data.ranges
        self.intensities = data.intensities

        (self.min_ranges, self.angles) = self.list_of_ranges(self.intensities, self.ranges, self.range_max,
                        self.range_min, self.n)

        print("List of angles:") 
        print(str(self.angles))
        print("List of ranges:") 
        print(str(self.min_ranges))
        print("Length of ranges list:")
        print(len(self.min_ranges))

        self.publisher()

    def nav_status_subscriber_callback(self, msg):
        print("Navigation status:")
        print(msg)
        # status_list = msg['status_list']
        # status = status_list['status']
        # return status

    def clean (self):
        self.move_to_room_result = self.move_to_room()

        # if self.move_to_room_result:
        print("Arrived at "+ self.destination)
        self.last_visited_corner = 0
        pt_ot = []
        while self.last_visited_corner < 4:
            if self.last_visited_corner == 3:
                self.dest_crds[0][0] += 0.25
                self.dest_crds[1][0] -= 0.25
                self.dest_crds[1][1] += 0.25
                self.dest_crds[2][0] -= 0.25
                self.dest_crds[2][1] -= 0.25
                self.dest_crds[3][0] += 0.25
                self.dest_crds[3][1] -= 0.25
                
            self.list_of_points = self.generate_points(self.last_visited_corner)
            print("List of points: ")
            print(self.list_of_points)
            print("Last visited corner: ")
            print(self.last_visited_corner)

            for point in self.list_of_points:
                pt_ot = []
                pt_ot.extend(point)
                if self.last_visited_corner == 0:
                    pt_ot.append(round(cos(0.5*pi), 2))
                if self.last_visited_corner == 1:
                    pt_ot.append(round(cos(0), 2))
                if self.last_visited_corner == 2:
                    pt_ot.append(-100)
                if self.last_visited_corner == 3:
                    pt_ot.append(round(cos(pi), 2))

                print("Point/Orientation: ")
                print(pt_ot)
                self.visited_points.append(pt_ot)
                move_result = self.move(pt_ot)
            
            if self.last_visited_corner + 1 < 4:
                self.last_visited_corner += 1
            else:
                self.last_visited_corner = 0

            # zmniejszanie spirali po ktorej porusza sie robot


    
    def move_to_room(self):

        print("Destination: " + self.destination)

        if self.destination == "bathroom":
            self.dest_crds = self.crds_dict["bathroom"]
            print("Goal -> Bathroom configured")

        elif self.destination == "lroom":
            self.dest_crds = self.crds_dict["lroom"]
            print("Goal -> Cloakroom configured")

        elif self.destination == "kitchen":
            self.dest_crds = self.crds_dict["kitchen"]
            print("Goal -> Kitchen configured")

        elif self.destination == "rubbish":
            self.dest_crds = self.crds_dict["rubbish"]
            print("Goal -> Rubbish configured")

        elif self.destination == "droom":
            self.dest_crds = self.crds_dict["droom"]
            print("Goal -> Dining room configured")

        elif self.destination == "office":
            self.dest_crds = self.crds_dict["office"]
            print("Goal -> Office configured")
        
        dest = self.dest_crds[0]
        dest.append(cos(0.5*pi))
        # addition of w-orientation
        # quaternion = quaternion_from_euler(0, 0, -1.5)

        print(dest[0], dest[1], dest[2])
        self.move(dest, flag=1)
        print()


    def move(self, dest, flag=0):

        client = actionlib.SimpleActionClient('move_base',MoveBaseAction)
        client.wait_for_server()

        goal = MoveBaseGoal()
        goal.target_pose.header.frame_id = "map"
        goal.target_pose.header.stamp = rospy.Time.now()
        goal.target_pose.pose.position.x = dest[0]
        goal.target_pose.pose.position.y = dest[1]
        goal.target_pose.pose.orientation.z = dest[2]
        goal.target_pose.pose.orientation.w = 1


        client.send_goal(goal)
        wait = client.wait_for_result()
        if not wait:
            rospy.logerr("Action server not available!")
            rospy.signal_shutdown("Action server not available!")
        else:
            return client.get_result()

        # # zadajemy 
        # if flag == 1:
        #     wait = client.wait_for_result()
        #     if not wait:
        #         rospy.logerr("Action server not available!")
        #         rospy.signal_shutdown("Action server not available!")
        #     else:
        #         return client.get_result()

        # # elif flag == 0:
        # #     wait = client.wait_for_result(rospy.Duration(8))
        # #     if not wait:
        # #         print("Plan not found, heading to the next local goal.")
        # #         # rospy.logerr("Action server not available!")
        # #         # rospy.signal_shutdown("Action server not available!")
        # #         return 
        #     else:
        #         print("Plan found with given time constraints")
        #         if self.departure_time:
        #             self.prev_departure_time = self.departure_time
        #         self.departure_time = datetime.datetime.now()
        #         self.elapsed_time = self.departure_time - self.prev_departure_time
        #         self.elapsed_time = int(self.elapsed_time.total_seconds())
        #         print("Time elapsed between 2 points:")
        #         print(self.elapsed_time)

        #         return client.get_result()
    



    def generate_points(self, last_visited_corner):
        step_size = 0.25
        stpt = self.dest_crds[last_visited_corner]
        if last_visited_corner != 3:
            endpt = self.dest_crds[last_visited_corner+1]
        else:
            endpt = self.dest_crds[0]
        stpt_x = stpt[0]
        stpt_y = stpt[1]
        endpt_x = endpt[0]
        endpt_y = endpt[1]
        distance = self.distance_between_points(stpt_x, endpt_x, stpt_y, endpt_y)
        list_of_points = []
        
        if stpt_x != endpt_x:
            # a = (stpt_y-endpt_y)/(stpt_x-endpt_x)
            distance_covered = step_size
            while distance_covered < distance:
                theta = atan2((endpt_y-stpt_y), (endpt_x-stpt_x))
                list_of_points.append((stpt_x+round(cos(theta), 2)*distance_covered, stpt_y+round(sin(theta), 2)*distance_covered))
                distance_covered += step_size

        else:
            distance_covered = step_size
            while distance_covered < distance:
                if(stpt_y >= endpt_y):
                    list_of_points.append((stpt_x, stpt_y-distance_covered))
                else:
                    list_of_points.append((stpt_x, stpt_y+distance_covered))
                distance_covered += step_size

        return list_of_points

    def distance_between_points(self, x1, x2, y1, y2):
        distance = round(sqrt((x1-x2)**2 + (y1-y2)**2), 2)
        return distance


if __name__ == '__main__':
    try:
        rospy.init_node('scan_server', anonymous=True)
        scan_server = ScanServer()
        rospy.spin()

    except rospy.ROSInterruptException:
        pass