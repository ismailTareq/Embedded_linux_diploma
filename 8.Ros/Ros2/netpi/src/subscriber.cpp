/*
    export ROS_DOMAIN_ID=30
    export ROS_IP=192.168.1.30
    export ROS_MASTER_URI=http://192.168.1.30:11311
*/



#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

int main()
{

    rclcpp::init(0, nullptr);
    auto node = rclcpp::Node::make_shared("subscriber");
    auto pub = node->create_subscription<std_msgs::msg::String>("chatter", 10, 
        [&](const std_msgs::msg::String::SharedPtr msg) {
            RCLCPP_INFO(node->get_logger(), "I heard: '%s'", msg->data.c_str());
        });
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}