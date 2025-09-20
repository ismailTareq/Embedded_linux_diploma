import rclpy
from my_service.srv import MyService
import sys

def send_request(client, request):
    response_future = client.call_async(request)
    rclpy.spin_until_future_complete(node, response_future)
    return response_future

def main():
    global node
    rclpy.init()
    node = rclpy.create_node('client')
    client = node.create_client(MyService, 'my_service')
    while not client.wait_for_service(timeout_sec=2.0):
        node.get_logger().info('Service not available, waiting again...')
    request = MyService.Request()
    request.a = int(sys.argv[1])
    request.b = int(sys.argv[2])
    response = send_request(client, request)
    if response.result() is not None:
        node.get_logger().info(f'Result: {request.a} + {request.b} = {response.result().sum}')
    else:
        node.get_logger().error('Service call failed')
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()