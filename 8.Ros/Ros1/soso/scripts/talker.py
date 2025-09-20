#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from soso.msg import v2v



def talker():
    #pub = rospy.Publisher("channel",String, queue_size=10)
    car_pub = rospy.Publisher("car_info",v2v, queue_size=10)
    rospy.init_node("talker", anonymous=True)
    car_info = v2v()
    car_info.id = 15
    car_info.name = "nigga"
    car_info.car_speed = 150
    car_info.battery_level = 0.48
    car_info.car_loc.x = 12.34
    car_info.car_loc.y = 56.78
    car_info.car_loc.theta = .9

    rate = rospy.Rate(10)  # 10hz
    while not rospy.is_shutdown():
        #hello_str = "hello bitch %s" % rospy.get_time()
        #rospy.loginfo(hello_str)
        #pub.publish(hello_str)
        rospy.loginfo(car_info)
        car_pub.publish(car_info)
        rate.sleep()


if __name__ == '__main__':
    # global freq
    # freq = rospy.get_param("freq")
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
