#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <vector>


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


	static Item deserializeItem(vector<string> properties);

	void setTitle(string title);
	void setAuthor(string author);
	void setPublisher(string publisher);
	void setISBN(string isbn);
	void setAvailibility(bool availability);
	string serializeToString(string separator = "|");
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
};

#endif
