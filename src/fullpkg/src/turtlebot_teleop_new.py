#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
import sys, select, termios, tty
from std_msgs.msg import String

def move(keyb):
    x = 0
    th = 0
    status = 0
    count = 0
    acc = 0.1
    target_speed = 0
    target_turn = 0
    control_speed = 0
    control_turn = 0
    speed = 1
    turn = 1
    key=keyb.data
    print key

    '''if (key=="i"):
        x=1
        th=0
    elif (key=="j"):
        x=0
        th=1
    elif (key=="l"):
        x=0
        th=-1
    elif (key==","):
        x=-1
        th=0

    print x, th, count'''
    
    moveBindings = {
            "i":(1,0),
            "j":(0,1),
            "l":(0,-1),
            ",":(-1,0),
                }

    speedBindings={
            'q':(1.1,1.1),
            'z':(.9,.9),
            'w':(1.1,1),
            'x':(.9,1),
            'e':(1,1.1),
            'c':(1,.9),
                }

    if key in moveBindings.keys():
        x = moveBindings[key][0]
        th = moveBindings[key][1]
        count = 0
        print x, th, count
    elif key in speedBindings.keys():
        speed = speed * speedBindings[key][0]
        turn = turn * speedBindings[key][1]
        count = 0

        print(vels(speed,turn))
        if (status == 14):
            print(msg)
        status = (status + 1) % 15
    elif key == ' ' or key == 'k' :
        x = 0
        th = 0
        control_speed = 0
        control_turn = 0
    else:
        count = count + 1
        if count > 4:
            x = 0
            th = 0
        #if (key == '\x03'):
        #    break
    
    print x, th, count

    target_speed = speed * x
    target_turn = turn * th

    if target_speed > control_speed:
        control_speed = min( target_speed, control_speed + 0.1 ) #0.02 in place of 0.1
    elif target_speed < control_speed:
        control_speed = max( target_speed, control_speed - 0.1 ) #0.02 in place of 0.1
    else:
        control_speed = target_speed

    if target_turn > control_turn:
        control_turn = min( target_turn, control_turn + 0.1 )
    elif target_turn < control_turn:
        control_turn = max( target_turn, control_turn - 0.1 )
    else:
        control_turn = target_turn

    twist = Twist()
    twist.linear.x = control_speed; twist.linear.y = 0; twist.linear.z = 0
    twist.angular.x = 0; twist.angular.y = 0; twist.angular.z = control_turn
    pub.publish(twist)
    print "after twist"

    #print("loop: {0}".format(count))
    #print("target: vx: {0}, wz: {1}".format(target_speed, target_turn))
    #print("publihsed: vx: {0}, wz: {1}".format(twist.linear.x, twist.angular.z))


def vels(speed,turn):
    return "currently:\tspeed %s\tturn %s " % (speed,turn)

if __name__=="__main__":
    
    msg = """
    Control Your Turtlebot!
    ---------------------------
    Moving around:
            i    
       j    k    l
            ,     

    q/z : increase/decrease max speeds by 10%
    w/x : increase/decrease only linear speed by 10%
    e/c : increase/decrease only angular speed by 10%
    space key, k : force stop
    anything else : stop smoothly

    CTRL-C to quit
    """

    
    speed = .2
    turn = 1

    print(msg)
    print(vels(speed,turn))

    rospy.init_node('turtlebot_teleop')
    kb = rospy.Subscriber("/keybind",String ,move)
    pub = rospy.Publisher('~cmd_vel', Twist, queue_size=5)

    while not rospy.is_shutdown():
        rospy.spin()