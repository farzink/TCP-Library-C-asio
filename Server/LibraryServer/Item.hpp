#ifndef ITEM_H
#define ITEM_H
#include <string>


using namespace std;

class Item {
public:
	Item(int, string, string, string, string);
	int getId();
	string getTitle();
	string getAuthor();
	string getPublisher();
	string getISBN();
	bool isAvailable();


	void setTitle(string title);
	void setAuthor(string author);
	void setPublisher(string publisher);
	void setISBN(string isbn);
	void setAvailibility(bool availability);

	string getOwner();
	void setOwner(string owner);
	Item() {};
	~Item() {};

protected:

private:
	int id;
	string title;
	string author;
	string publisher;
	string ISBN;
	bool availability;
	string owner;
};

#endif
