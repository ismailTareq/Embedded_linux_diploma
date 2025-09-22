#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

class MyNode : public rclcpp::Node
{
private:
    rclcpp::TimerBase::SharedPtr timer_;
    int count;

public:
    MyNode() : Node("publisher"), count(0)
    {
        RCLCPP_INFO(this->get_logger(),"constructor");
        timer_ = this->create_wall_timer(500ms,std::bind(&MyNode::timer_callback, this));

    }
    ~MyNode()
    {
        RCLCPP_INFO(this->get_logger(),"destructor");
    }
    void timer_callback()
    {
        RCLCPP_INFO(this->get_logger(),"timer callbacks %d", count++);
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