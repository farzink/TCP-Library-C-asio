#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H
#include <boost\algorithm\string.hpp>
#include <vector>
#include "ResponseAnalyzer.hpp"
#include <string>
#include <boost/asio.hpp>
#include <iostream>
#include "Logger.hpp"
#include "User.hpp"
#include "UserGenerator.hpp"
using namespace std;
namespace asio = boost::asio;



using namespace std;
class ClientManager {
public:
	ClientManager() : currentCommand("start:"), analyzer(), logger(), generator(), currentUser(), clientId("0") {
		this->currentUser = this->generator.getRandomUser();		
	}
	void run();
 
private:	
	bool validate(string name);
	ResponseAnalyzer analyzer;
	ServerCommand currentCommand;
	Logger logger;
	User currentUser;
	string clientId;
	UserGenerator generator;
};
#endif