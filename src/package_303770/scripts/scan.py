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
from package_303770.msg import _ranges


class ScanServer:
    def __init__(self):

        self.scan_subscriber = rospy.Subscriber('/scan', LaserScan, self.subscriber_callback)
        self.ranges_publisher = rospy.Publisher('/vacuum_sensors', _ranges, queue_size=10)
        self.move_base
        self.n = rospy.get_param("/sectors")

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


    def movebase_client():

        client = actionlib.SimpleActionClient('move_base',MoveBaseAction)
        print("Client created")
        destination = rospy.get_param("/destination")
        print("Destination: " + destination)
        print("Waiting for server")
        client.wait_for_server()
        print("Server ready")


        pos_bathroom = (-6.5, -2.0)
        pos_cloakroom = (-6.5, 3.0)
        pos_kitchen = (-3.0, 1.0)
        pos_rubbish = (1.0, 3.0)
        pos_dining_room = (5.0, -1.0)
        pos_office = (6.5, -1.5)


        goal = MoveBaseGoal()
        goal.target_pose.header.frame_id = "map"
        goal.target_pose.header.stamp = rospy.Time.now()

        destination = rospy.get_param("/destination")
        print("Destination: " + destination)

        if destination == "bathroom":
            goal.target_pose.pose.position.x = pos_bathroom[0]
            goal.target_pose.pose.orientation.w = pos_bathroom[1]
            print("Goal -> Bathroom configured")

        elif destination == "cloakroom":
            goal.target_pose.pose.position.x = pos_cloakroom[0]
            goal.target_pose.pose.orientation.w = pos_cloakroom[1]
            print("Goal -> Cloakroom configured")

        elif destination == "kitchen":
            goal.target_pose.pose.position.x = pos_kitchen[0]
            goal.target_pose.pose.orientation.w = pos_kitchen[1]
            print("Goal -> Kitchen configured")

        elif destination == "rubbish":
            goal.target_pose.pose.position.x = pos_rubbish[0]
            goal.target_pose.pose.orientation.w = pos_rubbish[1]
            print("Goal -> Rubbish configured")

        elif destination == "dining":
            goal.target_pose.pose.position.x = pos_dining_room[0]
            goal.target_pose.pose.orientation.w = pos_dining_room[1]
            print("Goal -> Dining room configured")

        elif destination == "office":
            goal.target_pose.pose.position.x = pos_office[0]
            goal.target_pose.pose.orientation.w = pos_office[1]
            print("Goal -> Office configured")

        client.send_goal(goal)
        print("Goal sent")

        wait = client.wait_for_result()
        print("Waiting for result")
        if not wait:
            rospy.logerr("Action server not available!")
            rospy.signal_shutdown("Action server not available!")
        else:
            return client.get_result()



if __name__ == '__main__':
    try:
        rospy.init_node('scan_server', anonymous=True)
        scan_server = ScanServer()
        rospy.spin()

    except rospy.ROSInterruptException:
        pass