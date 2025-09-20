import rospy
import cv2
import sys

from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image

bridge = CvBridge()

def image_callback(msg):
    print("Received an image!")
    global bridge
    try:
        cv_image = bridge.imgmsg_to_cv2(msg, "bgr8")
    except CvBridgeError as e:
        print(e)
        return
    
    cv2.imshow("original Image Window", cv_image)
    edge_image = cv2.Canny(cv_image, 100, 200)
    cv2.imshow("Edge Image Window", edge_image)
    ros_edge_image = bridge.cv2_to_imgmsg(edge_image)
    image_pub.publish(ros_edge_image)
    cv2.waitKey(3)

def main():
    rospy.init_node("image_viewer", anonymous=True)
    rospy.Subscriber("/cv_camera/image_raw", Image, image_callback)
    global image_pub
    image_pub = rospy.Publisher("/canny_image", Image, queue_size=10)
    try:
        rospy.spin()
    except KeyboardInterrupt:
        print("Shutting down")
    
    
    cv2.destroyAllWindows()



if __name__ == '__main__':
    main()




