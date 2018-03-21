#ifndef COMMANDDISPATHER_H
#define COMMANDDISPATHER_H
#include <string>
#include "Context.hpp"
#include "ItemRepository.hpp"
#include "UserRepository.hpp"
#include "TermColor.hpp"
#include <iostream>
using namespace std;
class CommandDispatcher {
public:
	CommandDispatcher(Context& context): context(context), itemRepository(context), userRepository(context){}
	string interpret(string command);
private:
	Context& context;
	ItemRepository itemRepository;
	UserRepository userRepository;
};

#endif