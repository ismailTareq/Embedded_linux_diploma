#include<boost/asio.hpp>
#include <iostream>
#include <string>

using namespace boost::asio;
using ip::tcp;
using std::string;

int main()
{
    boost::asio::io_service io_service;
    tcp::socket socket(io_service);
    socket.connect(
        tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234)
    );
    const string message = "Hello from client\n";
    boost::system::error_code error;
    boost::asio::write(socket, boost::asio::buffer(message), error);
    if (error) {
        std::cerr << "Error sending message: " << error.message() << std::endl;
    } else {
        std::cout << "Message sent successfully!" << std::endl;
    }
    boost::asio::streambuf response;
    boost::asio::read(socket, response, boost::asio::transfer_all(), error);
    if (error && error != boost::asio::error::eof) {
        std::cerr << "Error reading response: " << error.message() << std::endl;
    } else {
        std::cout << "Response received: " << boost::asio::buffer_cast<const char*>(response.data()) << std::endl;
    }
    socket.close();
    return 0;

}
