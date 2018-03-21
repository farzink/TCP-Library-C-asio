#include "stdafx.h"
#include "ClientManager.hpp"

#define BUFFER 1024
void ClientManager::run()
{
	srand(time(NULL));	
	string clientId = to_string(this->currentUser.getId());
	string serializedUser = this->generator.serializeUser(this->currentUser);
	const char *host = "localhost", *port = "2300";

	asio::io_service service;
	asio::ip::tcp::resolver resolver(service);
	try {
		bool stage = false;
		string option = "-1";
		asio::ip::tcp::resolver::query query(asio::ip::tcp::v4(),
			host, port);
		asio::ip::tcp::resolver::iterator end, iter = resolver.resolve(query);
		asio::ip::tcp::endpoint server(iter->endpoint());
		std::cout << "Connecting to " << server << '\n';
		
		//menu => 432342#start
		//menu item => #234234#menu#1
		for (;;)
		{
			asio::ip::tcp::socket socket(service, asio::ip::tcp::v4());
			socket.connect(server);
			std::string message = clientId + "#" + this->currentCommand.command + "#" + option;
			asio::write(socket, asio::buffer(message.c_str(), message.size()));
			socket.shutdown(asio::ip::tcp::socket::shutdown_send);


			char msg[BUFFER];
			boost::system::error_code ec;
			size_t sz = asio::read(socket, asio::buffer(msg, BUFFER), ec);
			if (!ec || ec == asio::error::eof) {
				msg[sz] = 0;
				if(analyzer.getStatusMessage(msg)[0] != "unchanged")
				(analyzer.getStatusMessage(msg)[1] != "1") ? logger.success(analyzer.getStatusMessage(msg)[0]) : logger.failure(analyzer.getStatusMessage(msg)[0]);


				if (this->analyzer.preAnalyze(msg) == "start") {
					this->currentCommand.command = "start:";
					option = "-1";
					continue;
				}				
				this->currentCommand=this->analyzer.analyze(msg, serializedUser);
				if (this->currentCommand.immediate)
					continue;
			}
			else {
				std::cerr << "Error reading response from server: "
					<< ec.message() << '\n';

			}
			
			

			while (true) {
				if (option == "2") {
					option = "-1";
					break;
				}					
				getline(cin, option);
				if (validate(option))
					break;
				else{
					/*std::cin.clear();
					cin.ignore(1024, '\n');*/					
					option = "-1";
					break;
				}
				std::cout << "only integers between 1 and 5\n";
				std::cin.clear();
				cin.ignore(1024, '\n');
			}
			if (option == "0")
				break;
		}


	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';

	}
}
bool ClientManager::validate(string name)
{
	if (name.length() == 0)
		return false;
	for (int i = 0; i < name.length(); i++)
		if (name[i] < '0' || name[i] > '9')
			return false; 
	return true;
}
