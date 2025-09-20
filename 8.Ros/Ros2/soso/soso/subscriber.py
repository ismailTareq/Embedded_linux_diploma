import rclpy
from std_msgs.msg import String

def main():
    rclpy.init()
    node = rclpy.create_node('soso_subscriber')
    sub = node.create_subscription(String, '/topic', lambda msg: node.get_logger().info('I heard: "%s"' % msg.data), 10)
    rclpy.spin_once(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()