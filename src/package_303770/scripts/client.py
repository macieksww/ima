#!/usr/bin/env python

import rospy
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
from math import cos, pi

def movebase_client():

    # utworzenie klienta akcji move_base
    client = actionlib.SimpleActionClient('move_base',MoveBaseAction)
    print("Client created")
    print("Waiting for server")
    client.wait_for_server()
    print("Server ready")

    # pobranie lokalizacji docelowej z parametru 
    destination = rospy.get_param("/destination")

    # slownik srds_dict zawiera wspolrzedne wierzcholkow pokoi
    crds_dict = {}
    crds_dict['droom'] = ([3.0, 0.5], [7.0, 0.5], [7.0, 4.2], [3.0, 4.2])
    crds_dict['kitchen'] = ([5.5, -4.5], [6.5, -4.5], [5.5, -1.0], [6.5, -1.0])
    crds_dict['rubbish'] = ([1.75, 4.75], [1.75, 1.5], [0.5, 1.5], [0.5, 4.75])
    crds_dict['lroom'] = ([-0.5, 0.5], [-0.5, 4.75], [-4.75, -4.75], [-4.75, 0.5])
    crds_dict['office'] = ([-5.5, 4.5], [-5.5, 1.5], [-7.0, 1.5], [-7.0, 4.5])
    crds_dict['bath'] = ([-5.5, 0.5], [-5.5, -3.5], [-7.0, -3.5], [-7.0, 0.5])

    print("Destination: " + destination)

    if destination == "bathroom":
        dest_crds = crds_dict["bathroom"]
        print("Goal -> Bathroom configured")

    elif destination == "lroom":
        dest_crds = crds_dict["lroom"]
        print("Goal -> Cloakroom configured")

    elif destination == "kitchen":
        dest_crds = crds_dict["kitchen"]
        print("Goal -> Kitchen configured")

    elif destination == "rubbish":
        dest_crds = crds_dict["rubbish"]
        print("Goal -> Rubbish configured")

    elif destination == "droom":
        dest_crds = crds_dict["droom"]
        print("Goal -> Dining room configured")

    elif destination == "office":
        dest_crds = crds_dict["office"]
        print("Goal -> Office configured")
    
    # punkt docelowy -> wspolrzedne 1. wierzcholka wybranego 
    # pomieszczenia
    # orientacja z skierowana do gory mapy
    dest = dest_crds[0]
    dest.append(cos(0.5*pi))

    # utworzenie obiektu typu goal
    # cel bedzie wysylany do serwera akcji - wezla nawigacyjnego 
    goal = MoveBaseGoal()
    # goal.target_pose.header.frame_id = "map"
    # goal.target_pose.header.stamp = rospy.Time.now()
    # goal.target_pose.pose.position.x = dest[0]
    # goal.target_pose.pose.position.y = [1]
    # goal.target_pose.pose.position.z = 0.0
    # goal.target_pose.pose.orientation.x = 0.0
    # goal.target_pose.pose.orientation.y = 0.0
    # goal.target_pose.pose.orientation.z = dest[2]
    # goal.target_pose.pose.orientation.w = 1.0

    goal.target_pose.header.frame_id = "map"
    goal.target_pose.header.stamp = rospy.Time.now()
    goal.target_pose.pose.position.x = dest[0]
    goal.target_pose.pose.position.y = dest[1]
    goal.target_pose.pose.orientation.z = dest[2]
    goal.target_pose.pose.orientation.w = 1

    client.send_goal(goal)
    print("Goal:")
    print("x: " + str(dest[0]))
    print("y: " + str(dest[1]))
    print("orientation z: " + str(dest[2]))

    # czekanie na informacje zwrotna z serwera akcji
    wait = client.wait_for_result()
    print("Waiting for result")

    # w przypadku przekroczenia czasu oczekiwania na odpowiedz
    # (parametr wait_for_result)
    if not wait:
        rospy.logerr("Action server not available!")
        rospy.signal_shutdown("Action server not available!")
    else:
        return client.get_result()

if __name__ == '__main__':
    try:
        rospy.init_node('movebase_client_py')
        result = movebase_client()
        if result:
            rospy.loginfo("Goal execution done!")
    except rospy.ROSInterruptException:
        rospy.loginfo("Navigation test finished.")