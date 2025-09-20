#!/usr/bin/env python3
import rospy
from geometry_msgs.msg import Pose2D
import matplotlib.pylab  as plt
import numpy as np
import time

def callback(data):
    rospy.loginfo("x: %f, y: %f, theta: %f", data.x, data.y, data.theta)
    plt.plot(data.x, data.y, marker=(3,0, data.theta*(180/3.14)-90), markersize=10, linestyle='None')
    plt.axis('equal')
    plt.draw()
    plt.pause(0.01)


def liston():
    rospy.init_node('listener', anonymous=True)
    rospy.Subscriber('/pioneer_loc', Pose2D, callback)
    rospy.spin()

if __name__ == '__main__':
    liston()


