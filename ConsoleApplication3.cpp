#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <string>
#include <boost/asio.hpp>
using namespace boost::asio;

class ShipmentInServer {
public:
    void shipment_main_void()
    {
        io_service service;
        ip::tcp::resolver resolver(service);
        ip::tcp::resolver::query query("www.b24-8dd5ja.bitrix24.site", "80");
        ip::tcp::resolver::iterator iter = resolver.resolve(query);
        ip::tcp::endpoint ep = *iter; 
        std::cout << ep.address().to_string() << std::endl;
        

    }
    void protected_channel()
    {

    }
};

class GetDataInServver {
   

};
int main()
{
    ShipmentInServer obj;
    obj.shipment_main_void();
    return 0;
}