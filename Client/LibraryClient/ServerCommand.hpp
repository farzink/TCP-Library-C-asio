#ifndef SERVERCOMMAND_H
#define SERVERCOMMAND_H
#include <string>


using namespace std;

class ServerCommand {
public:
	ServerCommand(string command, bool immediate = false) {
		this->command = command;
		this->immediate = immediate;
	}
	string command;
	bool immediate;
};
#endif
