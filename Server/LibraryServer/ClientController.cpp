#include "stdafx.h"
#include "ClientController.hpp"
#include "TermColor.hpp"
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
//ClientController::ClientController(Context& context, tcp::socket& socket) : context(context), client(socket), itemRepository(context)
//{
//
//}
void ClientController::serve() {
	

		ClientConnectionPTR connection = boost::make_shared<ClientConnection>(acceptor.get_io_service(), context);
		acceptor.async_accept(connection->getSocket(), [this, connection](const sys::error_code& ec) {
			if (ec) {
				std::cerr << "Failed to accept connection: "
					<< ec.message() << "\n";

			}
			else {
				connection->waitForReceive();
				serve();
			}
		});	
}







//
//
//
//std::cout << termcolor::green << "s" << std::endl;
//std::array<char, 256> recv_buf;
//client.open();
//std::size_t const received_bytes = client.receive(boost::asio::buffer(recv_buf));
//
//std::string const inputMessage(recv_buf.data(), received_bytes);
//std::cout << termcolor::green << "client served" << std::endl;
//
//std::string message = "some message";// make_daytime_string();
//boost::system::error_code ignored_error;
//boost::asio::write(client, boost::asio::buffer(message), ignored_error);
//	}
//	catch (std::exception& ex)
//	{
//		std::cerr << ex.what() << std::endl;
//	}
//}