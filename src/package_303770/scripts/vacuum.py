#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist
from math import pi, floor, atan2, sqrt, sin, cos
from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import *
from tf.transformations import euler_from_quaternion
from package_303770.msg import ranges
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
from math import sin, cos, atan2, pi



class ScanServer:
    def __init__(self):

        self.scan_subscriber = rospy.Subscriber('/vacuum_sensors', ranges, self.subscriber_callback)
        self.n = rospy.get_param("/sectors")
        self.destination = rospy.get_param("/destination")
        self.d_room_crds = ([3.0, 0.5], [7.0, 0.5], [7.0, 4.5], [3.0, 4.5])
        self.dest_crds = self.d_room_crds

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

    def clean (self):
        self.move_to_room_result = self.move_to_room()

        # if self.move_to_room_result:
        print("Arrived at "+ self.destination)
        self.last_visited_corner = 0
        pt_ot = []
        while self.last_visited_corner < 4:
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
                    pt_ot.append(round(cos(1.5*pi), 2))
                if self.last_visited_corner == 3:
                    pt_ot.append(round(cos(pi), 2))

                print("Point/Orientation: ")
                print(pt_ot)
                self.move(pt_ot)
            
            if self.last_visited_corner + 1 < 4:
                self.last_visited_corner += 1
            else:
                self.last_visited_corner = 0

            if self.last_visited_corner == 3:
                self.d_room_crds[0][1] += 0.5

            # if self.last_visited_corner == 0:
            #     self.d_room_crds[0][0] += 0.5
            #     self.d_room_crds[1][0] -= 0.5
            #     self.d_room_crds[1][1] += 0.5
            #     self.d_room_crds[2][0] -= 0.5
            #     self.d_room_crds[2][1] -= 0.5
            #     self.d_room_crds[2][0] += 0.5
            #     self.d_room_crds[2][1] -= 0.5


    
    def move_to_room(self):

        print("Destination: " + self.destination)
        pos_bathroom = (-6.5, -2.0)
        pos_cloakroom = (-6.5, 3.0)
        pos_kitchen = (-3.0, 1.0)
        pos_rubbish = (1.0, 3.0)
        pos_dining_room = (3.0, 0.5)
        pos_office = (6.5, -1.5)
        dest = []

        if self.destination == "bathroom":
            dest.extend(pos_bathroom)
            print("Goal -> Bathroom configured")

        elif self.destination == "cloakroom":
            dest.extend(pos_cloakroom)
            print("Goal -> Cloakroom configured")

        elif self.destination == "kitchen":
            dest.extend(pos_kitchen)
            print("Goal -> Kitchen configured")

        elif self.destination == "rubbish":
            dest.extend(pos_rubbish)
            print("Goal -> Rubbish configured")

        elif self.destination == "dining":
            dest.extend(pos_dining_room)
            print("Goal -> Dining room configured")

        elif self.destination == "office":
            dest.extend(pos_office)
            print("Goal -> Office configured")
        
        # addition of w-orientation
        dest.append(cos(0.5*pi))

        print(dest[0], dest[1], dest[2])
        self.move(dest)


    def move(self, dest):

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



    def generate_points(self, last_visited_corner):
        step_size = 0.25
        stpt = self.dest_crds[last_visited_corner]
        endpt = self.dest_crds[last_visited_corner+1]
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