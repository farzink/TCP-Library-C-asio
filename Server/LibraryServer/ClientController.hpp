//notice: some parts of this code is taken from Learning Boost C++ Libraries book
#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H



#include <boost/asio.hpp>
#include "Context.hpp"
#include "ItemRepository.hpp"


#include <iostream>
#include "TermColor.hpp"
#include <boost/date_time/posix_time/posix_time.hpp>
#include "ClientConnection.hpp"


using namespace std;
using boost::asio::ip::tcp;

typedef boost::shared_ptr<ClientConnection> ClientConnectionPTR;


class ClientController {
public:	
	//ClientController(Context& context, tcp::socket& socket);
	ClientController(asio::io_service& service, unsigned short p, Context& context): acceptor(service, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), p)), context(context) {		 
		 serve();		
	}
	void serve();
private:
	//ItemRepository itemRepository;
	Context &context;
	//tcp::socket& client;
	asio::ip::tcp::acceptor acceptor;	
};
#endif