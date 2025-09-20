import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, ActionClient

from wall_reached_action.action import WallReached
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
import sys

def send_goal(action_client,distance):
    goal_msg = WallReached.Goal()
    goal_msg.target_distance = distance
    action_client.wait_for_server()
    result = action_client.send_goal_async(goal_msg)
    return result

def main():
    global node
    rclpy.init()
    node = rclpy.create_node('mov_robot_client')
    action_client = ActionClient(node,WallReached,'wall_reached')
    while not action_client.wait_for_server(timeout_sec=1.0):
        node.get_logger().info('action server not available, waiting again...')
    distance = float(sys.argv[1])
    response = send_goal(action_client,distance)
    rclpy.spin_until_future_complete(node,response)
    print("anything")
    print("nigga")
    rclpy.shutdown()


if __name__ == '__main__':
    main()