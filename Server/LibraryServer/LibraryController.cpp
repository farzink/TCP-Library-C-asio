#include "stdafx.h"
#include "LibraryController.hpp"
#include <thread>
#include "ClientController.hpp"
#include <boost/thread.hpp>
#include <boost/bind.hpp>

LibraryController::LibraryController(Context& context): context(context), itemRepository(context)
{
}

void LibraryController::start()
{
	cout << termcolor::on_yellow << termcolor::red << "                                                                    " << endl;
	std::cout << termcolor::reset << termcolor::white << "--------------Library Server Starterd successfully---------------" << std::endl;
	cout << termcolor::on_yellow << termcolor::red << "                                                                    " << endl << termcolor::reset;
	cout << termcolor::on_green << termcolor::white << "Waiting for clients..." << endl << termcolor::reset;
	this->listen();
	//ItemRepository item(c);
	//Item i(c.getNextId(), "t", "t", "t", "t");
	//item.add(i);
	//item.remove(i);
	//auto t = item.getItemByTitle("t");
	/*if (t != NULL)
		cout << t->getAuthor() << endl;*/
}
void LibraryController::listen()
{
	using boost::asio::ip::tcp;
	try
	{
		
		boost::asio::io_service service;
		//tcp::resolver resolver(io_service);
		ClientController handler(service, 2300, context);
		service.run();

		//boost::thread_group pool;
		/*for (int i = 0; i < 4; ++i) {
			pool.create_thread([&service]() { service.run(); });			
		}*/


//		tcp::acceptor acceptor(service, tcp::endpoint(tcp::v4(), 2300));
//		
//		for (;;)
//		{			
//			tcp::socket socket(service);			
//			acceptor.accept(socket);
////			ClientController client(this->context, socket);
//			//client.serve();
//			//std::thread t(&ClientController::serve, client);
//		    
//			//boost::this_thread::sleep(boost::posix_time::seconds(2));
//		}
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

void LibraryController::handleClient(tcp::socket& socket)
{
	
}