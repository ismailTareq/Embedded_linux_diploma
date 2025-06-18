#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include <iostream>
#include <string>

using std::string;
using std::endl;

string Read(boost::asio::ip::tcp::socket& socket) 
{
    boost::asio::streambuf buffer;
    boost::asio::read_until(socket, buffer, "\n");
    
    string data = boost::asio::buffer_cast<const char*>(buffer.data());    
    return data;
}

void Send(boost::asio::ip::tcp::socket& socket ,const string& message) 
{
    boost::asio::write(socket, boost::asio::buffer(message + "\n"));
}

int main()
{
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::acceptor Acceptor(io_service, 
        boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 1234));
    std::cout << "Server is running on port 1234..." << std::endl;
    boost::asio::ip::tcp::socket Socket(io_service);
    Acceptor.accept(Socket);
    std::cout << "Client connected." << std::endl;
    string message = Read(Socket);
    std::cout << "Received: " << message << endl;
    Send(Socket, "Hello from server!");
    std::cout << "Sent: Hello from server!" << endl;
    Socket.close();
    std::cout << "Connection closed." << std::endl;
    return 0;
}
