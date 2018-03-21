#include "stdafx.h"
#include "ItemRepository.hpp"
#include "Context.hpp"
#include <vector>
#include <algorithm>
bool ItemRepository::update(Item model)
{
	try {
		auto item = this->getItemById(model.getId());
		if (item == NULL)
			return false;
		for (auto &item : context.items)
		{
			if (item.getId() == model.getId())
			{
				item.setTitle(model.getTitle());
				item.setAuthor(model.getAuthor());
				item.setPublisher(model.getPublisher());
				item.setISBN(model.getISBN());
				break;
			}
		}
		return true;
	}
	catch (exception ex) {
		return false;
	}
}
bool ItemRepository::insert(Item model)
{
	try {
		Item item(context.getNextId(), model.getTitle(), model.getAuthor(), model.getPublisher(), model.getISBN());
		context.items.push_back(item);
		return true;
	}
	catch(exception ex){
		return false;
	}
}
bool ItemRepository::reserveItem(int id) {
	return this->context.reserveItem(id);
}
Item* ItemRepository::getItemById(int id)
{
	for (auto &item : context.items)
	{
		if (item.getId() == id)
		{
			return &item;
		}
	}
	return NULL;
}
ItemRepository::ItemRepository(Context &context): context(context)
{
	this->context = context;
}

void ItemRepository::setContext(Context& context) {
	this->context = context;
}
void ItemRepository::add(Item item)
{
	context.items.push_back(item);
}
void ItemRepository::remove(Item item) {
	for (auto &item : context.items)
	{
		if (item.getId() == item.getId())
		{
			delete &item;
		}
	}
}

vector<Item> ItemRepository::getAllItems() {
	return context.items;
}
vector<Item> ItemRepository::getAllReservedItems() {
	vector<Item> result;
	for (auto &item : context.items)
	{
		if (!item.isAvailable())
		{
			result.push_back(item);
		}
	}
	return result;
}
vector<Item> ItemRepository::getAllAvailableItems() {
	vector<Item> result;
	for (auto &item : context.items)
	{
		if (item.isAvailable())
		{
			result.push_back(item);
		}
	}
	return result;
}
Item* ItemRepository::getItemByTitle(string title)
{
	for (auto &item : context.items) 
	{
		if (item.getTitle() == title)
		{
			return &item;			
		}
	}
	return NULL;
}
Item* ItemRepository::getItemByAuthor(string author)
{
	for (auto &item : context.items)
	{
		if (item.getTitle() == author)
		{
			
			return &item;
		}
	}
	return NULL;
}