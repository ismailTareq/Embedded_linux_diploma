#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "example_interfaces/msg/string.hpp"
#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

class MyNode : public rclcpp::Node
{
private:
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
public:
    MyNode() : Node("publisher")
    {
        publisher_ = this->create_publisher<example_interfaces::msg::String>("/my_topic", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&MyNode::publish_message, this));
    }
    void publish_message()
    {
        auto message = example_interfaces::msg::String();
        message.data = "Hello, this is a custom message!";
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        publisher_->publish(message);
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