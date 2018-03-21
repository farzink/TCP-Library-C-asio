#include "stdafx.h"
#include <vector>
#include "Context.hpp"
#include "Generator.hpp"
#include <algorithm>

/* generate secret number between 1 and 10: */
//iSecret = rand() % 10 + 1;
vector<Item> Context::items;
vector<User> Context::users;
boost::mutex Context::m;
void Context::init() {
	if (Context::items.empty()) {
		Generator g;
		Context::items = g.generateItems(10);
	}
	if (users.empty()) {
		Generator g;
		//Context::users = g.generateUsers();
	}
}
int Context::getNextId() {
	return std::max_element(items.begin(), items.end(), compare)->getId() + 1;
}
bool Context::compare(Item a, Item b)
{
	return (a.getId() < b.getId());
}
bool Context::reserveItem(int id) {	
	m.lock();
	for (auto &item : items)
	{
		if (item.getId() == id)
		{
			if (!item.isAvailable()) {
				m.unlock();
				return false;
			}
			item.setAvailibility(false);
			m.unlock();
			return true;
		}
	}
	m.unlock();
	return false;	
}