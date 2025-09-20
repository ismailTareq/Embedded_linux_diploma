from my_service.srv import service
from my_service.srv import serviceRequest
from my_service.srv import serviceResponse


import rospy
import sys


def add_two_ints(x, y):
    rospy.wait_for_service('add_two_int')
    try:
        add = rospy.ServiceProxy('add_two_int', service) # Create a service object
        resp1 = add(x, y)  # Call the service
        return resp1.sum 
    except rospy.ServiceException as e:
        print("Service call failed: %s" % e)

if __name__ == "__main__":
    if len(sys.argv) == 3:
        x = int(sys.argv[1])
        y = int(sys.argv[2])
    else:
        print("usage: add_two_ints_client.py X Y")
        sys.exit(1)
    print("Requesting %s+%s" % (x, y))
    print("Result: %s" % add_two_ints(x, y))


