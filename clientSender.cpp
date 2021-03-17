#include "CryptDouble.h"
#include <iostream>
#include <fstream>
#include <boost/asio.hpp>
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>
#include <cstdlib>
using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;
class GetData {
public:
    string read_(tcp::socket& socket) {
        boost::asio::streambuf buf;
        boost::asio::read_until(socket, buf, "\n");
        string data = boost::asio::buffer_cast<const char*>(buf.data());
        return data;
    }
    void send_(tcp::socket& socket, const string& message) {
        const string msg = message + "\n";
        boost::asio::write(socket, boost::asio::buffer(message));
    }
    std::ofstream get_file() //
    {
        boost::asio::io_service io_service;
    
        tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(),  80));
      
        tcp::socket socket_(io_service);
      
        acceptor_.accept(socket_);

        string fileName = "pass.kblt";
        string message = read_(socket_);
        std::ofstream file;
        file.open(fileName);
        file << message << std::endl;
        file.close();
        return file;
    }
};
class Shipment  {
public:

    void server_api() {

      
        ifstream file("pass.kblt");
        file.open("pass.kblt");
        std::stringstream ss;
        ss << file.rdbuf();
        std::string str(ss.str());
        const string iu = str;
       

        boost::asio::io_service io_service;
  
        tcp::socket socket(io_service);
   
        socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("localhost"), 80));

       
        boost::system::error_code error;
        boost::asio::write(socket, boost::asio::buffer(iu), error);
  
        
        boost::asio::streambuf receive_buffer;
        boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
        if (error && error != boost::asio::error::eof) {
            cout << "receive failed: " << error.message() << endl;
        }
        else {
            const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
            cout << data << endl;
        }
        file.close();

    }
    void file_transit(std::fstream& file)//
    {}
protected:
    
};

int main() {
    GetData ob;
    ob.get_file();
    Shipment obj;
    obj.server_api();

    return 0;
}
