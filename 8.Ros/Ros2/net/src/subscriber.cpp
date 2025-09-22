#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "example_interfaces/msg/string.hpp"
#include <chrono>
#include <iostream>


using namespace std::chrono_literals;


class MyNode : public rclcpp::Node
{
private:
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;
public:
    MyNode() : Node("subscriber")
    {
        subscriber_ = this->create_subscription<example_interfaces::msg::String>("/my_topic",10,std::bind(&MyNode::subscribe_message,this ,std::placeholders::_1));
    }
    void subscribe_message(const example_interfaces::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
        
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