from SmachVacuum import Vacuum
import rospy
import smach

class GoToRoom(smach.State):
    def __init__(self):
        smach.State.__init__(self, output_keys=['in_room', 'obstacle_detected', 'out_of_battery'],
                                            input_keys=['room'],
                                            outcomes=['outcome1'])
                                            # output_keys=['position'])

    def execute(self, userdata):
        rospy.loginfo('Executing state GoToRoom')
        room = userdata.room
        vacuum = Vacuum()
        return 'in_room'

class CleanRoom(smach.State):
    def __init__(self):
        smach.State.__init__(self, output_keys=['cleaned', 'obstacle_detected', 'out_of_battery'],
                                    input_keys=['room'],
                                    outcomes=['outcome1']           )

    def execute(self, userdata):
        rospy.loginfo('Executing state CleanRoom')
        vacuum = Vacuum()
        vacuum.move_to_room()

        if True:
            return 'cleaned'
        elif True:
            return 'obstacle_detected'
        else:
            return 'out_of_battery'

class OmitObstacle(smach.State):
    def __init__(self):
        smach.State.__init__(self, output_keys=['obstacle_omitted'],
                                outcomes=['outcome1'])

    def execute(self, userdata):
        rospy.loginfo('Executing state OmitObstacle')

        if True:
            return 'obstacle_omitted'

class Charge(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['outcome1'],
                                    output_keys=['charged'])

    def execute(self, userdata):
        rospy.loginfo('Executing state Charge')
        if True:
            return 'charged'

class Charge(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['outcome1'],
                                    output_keys=['charged'])

    def execute(self, userdata):
        rospy.loginfo('Executing state Charge')
        if True:
            return 'charged'
        

def main():
    rospy.init_node('smach_state_machine')
       # Create the top level SMACH state machine
    cleaning_vision_system = smach.StateMachine(input_keys=['room'],
                                                outcomes=['outcome1'])

    # Open the container
    with cleaning_vision_system:

        # Create the sub SMACH state machine 
        cleaning_system = smach.StateMachine(outcomes=['outcome1'])

        # Open the container 
        with cleaning_system:

            # Add states to the container 
            smach.StateMachine.add('GOTO_ROOM', GoToRoom(),
                                    transitions={'outcome1':'CLEAN_ROOM'}, 
                                    remapping={'room':'sm_room'})

            smach.StateMachine.add('CLEAN_ROOM', CleanRoom(),
                                   transitions={'outcome1':'GOTO_ROOM'})

        smach.StateMachine.add('CLEANING_SYSTEM', cleaning_system,
                               transitions={'outcome1':'outcome1'})

        # smach.StateMachine.add('CHARGE', Charge(),
        #                 transitions={'outcome1':'SUB'})

        outcome = cleaning_vision_system.execute()



if __name__ == '__main__':
    main()