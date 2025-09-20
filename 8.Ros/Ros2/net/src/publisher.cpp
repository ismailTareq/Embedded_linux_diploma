/*
    export ROS_DOMAIN_ID=30
    export ROS_IP=192.168.1.8
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
    auto node = rclcpp::Node::make_shared("publisher");
    auto pub = node->create_publisher<std_msgs::msg::String>("chatter", 10);
    auto timer = node->create_wall_timer(100ms,
        [&](){
            auto msg = std_msgs::msg::String();
            msg.data = "Hello, ismail";
            RCLCPP_INFO(node->get_logger(), "Publishing: '%s'", msg.data.c_str());
            pub->publish(msg);
        });
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
