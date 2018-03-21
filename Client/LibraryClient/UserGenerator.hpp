#ifndef USERGENERATOR_H
#define USERGENERATOR_H
#include <vector>
#include <time.h>
#include <string>
#include "User.hpp"
#include "Item.hpp"

using namespace std;



class UserGenerator {
public:
	UserGenerator() { srand(time(NULL)); this->id = 0; };
	//int getId();

	//vector<Item> generateItems(int size = 10);
	//vector<User> generateUsers(int size = 5);

	//void setTitle(string title);
	User UserGenerator::getRandomUser();
	string serializeUser(User user, string separator="|");

	~UserGenerator() {};

protected:

private:
	int id;
	string names[20] = { "Steve", "Paul", "John", "Albert", "Jane",
		"Fred", "Dana", "Arnold", "arthur", "Jack",
		"Max", "Robert", "Carl", "Maria", "Peter",
	"Gilbert", "Kris", "Tom", "Bruce", "Kate"};
	string ages[10] = { "18", "19", "20", "21", "22",
		"23", "24", "25", "26", "28" };	
	
};

#endif