#ifndef GENERATOR_H
#define GENERATOR_H
#include <vector>
#include <time.h>
#include <string>
#include "User.hpp"
#include "Item.hpp"

using namespace std;



class Generator {
public:
	Generator() { srand(time(NULL)); this->id = 0; };
	//int getId();
	
	vector<Item> generateItems(int size=10);
	vector<User> generateUsers(int size=5);

	//void setTitle(string title);

	
	~Generator() {};

protected:

private:
	int id;
	string titles[16] = { "C", "C++", "Python", "Ruby", "PHP", "Haskell", "Erlang", "Java", "C Sharp", "Java Script", "Perl", "Angular", "HTML", "CSS", "MongoDB", "Fsharp" };
	string preTitles[5] = { "Beginning", "Advanced", "Intermediate", "Professional", "Practical" };
	string postTitles[6] = { "For Dreamers", "For Dummies", "In Progress", "In 14 Weeks", "In Depth", "For Dumbs" };
	string authors[12] = { "James Codeman", "Steve Zebra", "Peter Dumb", "Ken Pak", "Morris Metterson", "Bob Matress", "Philip Dubuois", "Ernest McFlusk", "Tim Notroh", "Larry Fest", "Tetris Mam", "Jan Last" };
	string publishers[8] = { "Kings", "Bings", "OTG", "Ducks", "Mirage", "Tomorrow`s hope", "Techniques", "Farmers" };
	int getNextId();
	string getRandomCompleteTitle();
	string getRandomTitle();
	string getRandomPreTitle();
	string getRandomPostTitle();
	string getRandomAuthor();
	string getRandomISBN();
	string getRandomPublisher();
};

#endif