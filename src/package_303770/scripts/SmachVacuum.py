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
from actionlib_msgs.msg import GoalStatus, GoalStatusArray
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
from math import sin, cos, atan2, pi

import datetime



class Vacuum:
    def __init__(self, room):

        self.nav_status_subscriber = rospy.Subscriber('/move_base/status', GoalStatusArray, self.nav_status_subscriber_callback)
        self.destination = room
        self.crds_dict = {}

        # wspolrzedne wierzcholkow poszczegolnych pokoi
        self.crds_dict['droom'] = ([3.0, 0.5], [7.0, 0.5], [7.0, 4.2], [3.0, 4.2])
        self.crds_dict['kitchen'] = ([5.5, -4.5], [6.5, -4.5], [5.5, -1.0], [6.5, -1.0])
        self.crds_dict['rubbish'] = ([0.5, 1.5], [1.75, 1.5], [1.75, 4.75],[0.5, 4.75])
        self.crds_dict['lroom'] = ([-4.5, 0.5], [-0.5, 0.5], [-0.5, 4.75], [-4.5, 4.75], )
        self.crds_dict['office'] = ([-5.5, 4.5], [-5.5, 1.5], [-7.0, 1.5], [-7.0, 4.5])
        self.crds_dict['bath'] = ([-5.5, 0.5], [-5.5, -3.5], [-7.0, -3.5], [-7.0, 0.5])
        self.departure_time = datetime.datetime.now()
        self.prev_departure_time = datetime.datetime.now()
        self.elapsed_time = datetime.datetime.now()
        self.cannot_reach_local_goal = False
        self.visited_points = []
        self.cleaning_finished = False

        cleaning_finished = self.clean()
        print("Cleaning finished")


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
        status_list = msg.status_list
        # print(type(status_list))
        # print(status_list)
        for status in status_list:
            # print(status.status)
            # print(status.text)
            pass

    def clean (self):
        self.move_to_room_result = self.move_to_room()

        if self.cleaning_finished is False:        
            print("Arrived at "+ self.destination)
            self.last_visited_corner = 0
            pt_ot = []
            circle_idx = 0
            distance_between_vertexes = 1


            # wspolczynnik przekazany funkcji move, w ktorej
            # wywolywana jest funkcja wait_for_result od stosu nawigacji
            # domyslnie czas na feedback od planer to 8 sekund
            # w wypadku gdy planer nie znajdzie sciezki do zadanego punktu, wybieramy nastepy
            # wowczas czas oczekiwania mnozony jest * wspoczynnik time_to_reach_point_coeff
            # tak aby robot mial wiecj czasu na dojechanie do bardziej odleglego punktu
            time_to_reach_point_coeff = 1

            # dopoki spelniony jest warunek, ze odleglosc wierzcholkow od siebie
            # < 0.5 metra, pokoj nie jest sprzatniety

            while distance_between_vertexes > 0.5:
                # zmniejszanie spirali po ktorej porusza sie robot
                if self.last_visited_corner == 3:
                    # jezeli jest to pierwsze okrazenie pokoju przez robota
                    # wowczas pierwszy wierzcholek zmnieniamy tylko w osi y
                    # w przypadku kolejnych okrazeni zmnieniamy w obu osiach

                    if circle_idx == 0:
                        self.dest_crds[0][1] += 0.25
                    else:
                        self.dest_crds[0][0] += 0.25
                        self.dest_crds[0][1] += 0.25
                    self.dest_crds[1][0] -= 0.25
                    self.dest_crds[1][1] += 0.25
                    self.dest_crds[2][0] -= 0.25
                    self.dest_crds[2][1] -= 0.25
                    distance_between_vertexes = self.distance_between_points(self.dest_crds[0][0], self.dest_crds[3][0], self.dest_crds[0][1], self.dest_crds[3][1])
                    self.dest_crds[3][0] += 0.25
                    self.dest_crds[3][1] -= 0.25
                    circle_idx += 1

                # wywolanie funkcji generujacej punkty od ostatniego odwiedzonego wierzcholka
                    
                self.list_of_points = self.generate_points(self.last_visited_corner)
                print("List of points: ")
                print(self.list_of_points)
                print("Last visited corner: ")
                print(self.last_visited_corner)

                # do celu zadanego w plaszczyznie kartezjanskiej
                # dodajemy orientacje, ktora robot powinien osiagnac


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
                    move_result = self.move(pt_ot, 0, time_to_reach_point_coeff)

                    # jezeli funkcja move zwroci 0 ->
                    # stos nawigacji nie znajdzie planu do zadanego celu
                    if move_result == 0:
                        time_to_reach_point_coeff += 1
                        print("Time to reach the next point extended")
                    else:
                        time_to_reach_point_coeff = 1

                print("Path finished")
                if self.last_visited_corner + 1 < 4:
                    self.last_visited_corner += 1
                else:
                    self.last_visited_corner = 0

            # ustawienie flagi oznaczajacej koniec sprzatania na 1
            self.cleaning_finished = True
            return 
        else:
            return 


    # funkcja realizujaca ruch do zadanego pokoju 
    # wybor pokoju nastepuje jako ustawienie wartosci 
    # parametru ROS w momencie wywolania wezla vacuum
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
        self.move(dest, 1, 1)
        print()


    def move(self, dest, flag, time_to_reach_point_coeff):

        client = actionlib.SimpleActionClient('move_base',MoveBaseAction)
        client.wait_for_server()

        goal = MoveBaseGoal()
        goal.target_pose.header.frame_id = "map"
        goal.target_pose.header.stamp = rospy.Time.now()
        goal.target_pose.pose.position.x = dest[0]
        goal.target_pose.pose.position.y = dest[1]
        goal.target_pose.pose.orientation.z = dest[2]
        goal.target_pose.pose.orientation.w = 1

        print("FLAGA")
        print(flag)


        client.send_goal(goal)

        # zadajemy 
        if flag == 1:
            wait = client.wait_for_result()
            if not wait:
                rospy.logerr("Action server not available!")
                rospy.signal_shutdown("Action server not available!")
            else:
                return client.get_result()

        elif flag == 0:
            print("Time to reach point: " + str(time_to_reach_point_coeff*8))
            wait = client.wait_for_result(rospy.Duration(8*time_to_reach_point_coeff))
            if not wait:
                print("Plan not found, heading to the next local goal.")
                # rospy.logerr("Action server not available!")
                # rospy.signal_shutdown("Action server not available!")
                return 0
            else:
                print("Plan found with given time constraints")
                if self.departure_time:
                    self.prev_departure_time = self.departure_time
                self.departure_time = datetime.datetime.now()
                self.elapsed_time = self.departure_time - self.prev_departure_time
                self.elapsed_time = int(self.elapsed_time.total_seconds())
                print("Time elapsed between 2 points:")
                print(self.elapsed_time)

                return client.get_result()
    



    def generate_points(self, last_visited_corner):

        # wielkosc kroku - dystansu pomiedzy kolejnymi punktami
        step_size = 0.5

        # punkt startowy i koncowy generacji
        stpt = self.dest_crds[last_visited_corner]
        if last_visited_corner != 3:
            endpt = self.dest_crds[last_visited_corner+1]
        else:
            endpt = self.dest_crds[0]
        stpt_x = stpt[0]
        stpt_y = stpt[1]
        endpt_x = endpt[0]
        endpt_y = endpt[1]

        # wyznaczenie odleglosci pomiedzy punktem startowym i koncowym
        distance = self.distance_between_points(stpt_x, endpt_x, stpt_y, endpt_y)
        list_of_points = []

        # generowanie punktow na prostej laczacej punkt startowy i koncowy
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

    # funkcja pomocniczna sluzaca do wyznaczenia odleglosci pomiedzy
    # dwoma punktami w plaszczyznie kartezjanskiej

    def distance_between_points(self, x1, x2, y1, y2):
        distance = round(sqrt((x1-x2)**2 + (y1-y2)**2), 2)
        return distance
