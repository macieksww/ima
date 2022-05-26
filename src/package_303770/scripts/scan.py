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


class ScanServer:
    def __init__(self):
        
        # konfiguracja Subscribera na temacie /scan
        # konfiguracja Publisher na temacie /vacuum_sensors
        # liczba sektorow pobrana jako parametr ROS

        self.scan_subscriber = rospy.Subscriber('/scan', LaserScan, self.subscriber_callback)
        self.ranges_publisher = rospy.Publisher('/vacuum_sensors', ranges, queue_size=10)
        self.n = int(rospy.get_param("/sectors"))

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
        min_ranges = self.list_of_ranges(self.ranges, self.n)
        print(min_ranges)
        self.ranges_publisher.publish(min_ranges)

    def list_of_ranges(self, ranges, n):
        it = 0
        min_ranges = []
        angle = int(floor(len(ranges)/n))
        while it < n:
            min_range = min(ranges[it*angle:(it+1)*angle])
            min_ranges.append(min_range)
            min_ranges
            it = it+1
        return min_ranges


if __name__ == '__main__':
    try:
        rospy.init_node('scan_server', anonymous=True)
        scan_server = ScanServer()
        rospy.spin()

    except rospy.ROSInterruptException:
        pass