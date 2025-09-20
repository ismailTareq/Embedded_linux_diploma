import rclpy
from my_service.srv import MyService

def callback(request, response):
    global node
    response.sum = request.a + request.b
    node.get_logger().info(f'Service called with a={request.a}, b={request.b}, sum={response.sum}')
    return response

def main():
    global node 
    rclpy.init()
    node = rclpy.create_node('server')
    node.create_service(MyService, 'my_service', callback)
    rclpy.spin_once(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
