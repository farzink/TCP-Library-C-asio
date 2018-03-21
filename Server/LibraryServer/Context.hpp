#ifndef CONTEXT_H
#define CONTEXT_H
#include <vector>
#include "Item.hpp"
#include "User.hpp"
#include <boost\thread\mutex.hpp>

using namespace std;

class Context {
public:
	static Context& getInstance()
	{
		static Context instance;
		instance.init();
		return instance;
	}
private:
	Context() {}
	Context(Context const&);	
	static void init();
	static bool Context::compare(Item a, Item b);
	static boost::mutex m;

public:
	static vector<Item> items;
	static vector<User> users;
	
	static int getNextId();
	static bool reserveItem(int id);
	//Context(Context const&) = delete;
	//void operator=(Context const&) = delete;



};
#endif