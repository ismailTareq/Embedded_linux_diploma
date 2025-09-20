import rclpy
from std_msgs.msg import String




def main():
    rclpy.init()
    node = rclpy.create_node('soso_publisher')
    pub = node.create_publisher(String, '/topic', 10)
    msg = String()
    i = 0

    def timer_callback():
        nonlocal i
        msg.data = "hello ismail %d" % i
        node.get_logger().info('Publishing: "%s"' % msg.data)
        i += 1
        pub.publish(msg)

    timer = node.create_timer(0.5, timer_callback)
    rclpy.spin(node)
    node.destroy_timer(timer)    
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()