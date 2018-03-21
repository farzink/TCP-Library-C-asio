#ifndef ITEMREPOSITORY_H
#define ITEMREPOSITORY_H
#include <string>
#include "Context.hpp"

using namespace std;

class ItemRepository {
public:
	bool reserveItem(int id);
	Item* getItemById(int id);
	vector<Item> getAllItems();
	vector<Item> getAllReservedItems();
	vector<Item> getAllAvailableItems();	
	Item* getItemByTitle(string title);
	Item* getItemByAuthor(string title);
	bool update(Item item);
	bool insert(Item item);
	void setContext(Context&);
	void add(Item item);
	void remove(Item item);

	ItemRepository(Context&);
	~ItemRepository() {};
protected:

private:
	
	Context& context;
};

#endif
