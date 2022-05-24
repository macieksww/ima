#!/usr/bin/env python
# license removed for brevity

import rospy
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal

def movebase_client():

    client = actionlib.SimpleActionClient('move_base',MoveBaseAction)
    print("Client created")
    print("Waiting for server")
    client.wait_for_server()
    print("Server ready")

    pos_bathroom = (-6.5, -2.0)
    pos_cloakroom = (-6.5, 3.0)
    pos_kitchen = (-3.0, 1.0)
    pos_cloakroom = (1.0, 3.0)
    pos_bathroom = (5.0, -1.0)
    pos_cloakroom = (6.5, -1.5)


    goal = MoveBaseGoal()
    goal.target_pose.header.frame_id = "map"
    goal.target_pose.header.stamp = rospy.Time.now()
    goal.target_pose.pose.position.x = 0.5
    goal.target_pose.pose.orientation.w = 1.0
    print("Goal configured")

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
        rospy.init_node('movebase_client_py')
        result = movebase_client()
        if result:
            rospy.loginfo("Goal execution done!")
    except rospy.ROSInterruptException:
        rospy.loginfo("Navigation test finished.")