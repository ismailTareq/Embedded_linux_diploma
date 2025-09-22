#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

class MyNode : public rclcpp::Node
{
private:
    rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client_;
public:
    MyNode() : Node("client")
    {
        client_ = this->create_client<example_interfaces::srv::AddTwoInts>("/my_topic");
    }
    void add_two_ints()
    {
           while(!client_->wait_for_service(1s))
        {
            RCLCPP_INFO(this->get_logger(),"service not available, waiting again...");
        }
        auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
        request->a = 5;
        request->b = 3; 
        auto result = client_->async_send_request(request,std::bind(&MyNode::response_callback,this,std::placeholders::_1));
    }
    void response_callback(rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedFuture future)
    {
        RCLCPP_INFO(this->get_logger(),"Sum: %ld",future.get()->sum);
    }
    
    ~MyNode()
    {
        RCLCPP_INFO(this->get_logger(),"destructor");
    }
    
};


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>();
    node->add_two_ints();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}