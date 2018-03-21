//notice: some parts of this code is taken from Learning Boost C++ Libraries book


#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H
#include "Context.hpp"
#include "CommandDispather.hpp"
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include "Logger.hpp"
#include <iostream>
#define BUFFER 1024


namespace asio = boost::asio;
namespace sys = boost::system;

class ClientConnection
	: public boost::enable_shared_from_this<ClientConnection> {
public:
	ClientConnection(asio::io_service& service, Context &context) :
		socket(service), context(context), dispatcher(context) {}

	asio::ip::tcp::socket& getSocket() {
		return socket;
	}

	void waitForReceive() {
		auto thisPtr = shared_from_this();
		async_read(socket, asio::buffer(buf, sizeof(buf)), [thisPtr](const sys::error_code& ec, size_t sz) {
			if (!ec || ec == asio::error::eof) {
				//thisPtr->reply();
				thisPtr->buf[sz] = '\0';
				//auto d = thisPtr->dispatcher.interpret(thisPtr->buf);
				thisPtr->reply(thisPtr->dispatcher.interpret(thisPtr->buf));
				std::cout << thisPtr->buf << '\n';

				if (!ec) { thisPtr->waitForReceive(); }

			}
			else {
				std::cerr << "Error receiving data from "
					"client: " << ec.message() << "\n";

			}
		});

	}

	void reply(string response) {
		
		Logger().L2("--------- cliend request is received--------------");
		auto thisPtr = shared_from_this();
		async_write(socket, asio::buffer(response.c_str(), strlen(response.c_str())), [thisPtr](const sys::error_code& ec, size_t sz) {
			if (ec) {
				if (ec == asio::error::eof) {
					thisPtr->socket.close();

				}
				std::cerr << "Failed to send response to "

					"client: " << ec.message() << '\n';

			}
		});

	}

private:
	asio::ip::tcp::socket socket;
	char buf[BUFFER];
	Context &context;
	CommandDispatcher dispatcher;

};

#endif