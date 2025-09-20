import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer

from wall_reached_action.action import WallReached
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan


def callback(goal_handle):
    global pub
    global node
    global distance
    node.get_logger().info('received goal request {0}'.format(goal_handle.request))
    goal_msg = goal_handle.request.target_distance
    node.get_logger().info('goal distance: {0}'.format(goal_msg))
    feedback_msg = WallReached.Feedback()
    result_msg = WallReached.Result()
    robot_vel = Twist()
    while distance >= goal_msg:
        rclpy.spin_once(node)
        robot_vel.linear.x = 0.3
        feedback_msg.remaining_distance = distance
        goal_handle.publish_feedback(feedback_msg)
        pub.publish(robot_vel)
        print(distance)
    robot_vel.linear.x = 0.0
    pub.publish(robot_vel)
    result_msg.reached = True
    goal_handle.succeed()
    node.get_logger().info('goal succeeded')
    return result_msg

def laser_callback(msg):
    global distance
    global node
    distance = min(min(msg.ranges[0:10]),12)



def main():
    global node
    global pub
    rclpy.init()
    node = rclpy.create_node('mov_robot_server')
    action_server = ActionServer(node,WallReached,'wall_reached',callback)
    pub = node.create_publisher(Twist,'/cmd_vel',10)
    sub = node.create_subscription(LaserScan,'/scan',laser_callback,10)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass 
    action_server.destroy()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()