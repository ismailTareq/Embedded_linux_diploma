#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
#include <chrono>
#include <iostream>

using namespace std::placeholders;

class MyNode : public rclcpp::Node
{
private:
    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr server_;
public:
    MyNode() : Node("server")
    {
        server_ = this->create_service<example_interfaces::srv::AddTwoInts>("/my_topic",std::bind(&MyNode::callback,this,_1,_2));
        
    }
    void callback(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
                  std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response)
    {
        response->sum = request->a + request->b;
        RCLCPP_INFO(this->get_logger(), "Incoming request\na: %ld b: %ld", request->a, request->b);
        RCLCPP_INFO(this->get_logger(), "Sending back response: [%ld]", response->sum);
    }
    ~MyNode()
    {
        RCLCPP_INFO(this->get_logger(),"destructor");
    }
    
};

int main()
{
    rclcpp::init(0, nullptr);
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}