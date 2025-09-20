from my_service.srv import service
from my_service.srv import serviceRequest
from my_service.srv import serviceResponse

import rospy
import time

def handle_add_two_ints(req):
    print("Returning [%s + %s = %s]" % (req.x, req.y, (req.x + req.y)))
    time.sleep(3)  # Simulate a delay
    sum = serviceResponse(req.x + req.y)
    return sum


def addtwoints():
    rospy.init_node('add_two_ints_server')
    ser = rospy.Service('add_two_int', service, handle_add_two_ints)
    print("Ready to add two ints.")
    rospy.spin()




if __name__ == "__main__":
    addtwoints()
