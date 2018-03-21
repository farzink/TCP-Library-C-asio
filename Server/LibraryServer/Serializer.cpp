#include "stdafx.h"
#include "Serializer.hpp"
#include <boost\algorithm\string.hpp>

Item Serializer::deserializeItem(string content, string separator) {
	vector<string> properties;
	boost::split(properties, content, boost::is_any_of("|"));
	Item item(atoi(properties[0].c_str()), properties[1], properties[2], properties[3], properties[4]);
	return item;
}
User Serializer::deserializeUser(string content, string separator) {
	vector<string> properties;
	boost::split(properties, content, boost::is_any_of("|"));
	User user(properties[0], properties[1], properties[2], properties[3]);
	return user;
}
string Serializer::serializeItem(Item item, string separator)
{
	return to_string(item.getId()) + separator + item.getTitle() + separator + item.getAuthor() + separator + item.getPublisher() + separator + item.getISBN() + to_string(item.isAvailable());
}
string Serializer::serializeItems(vector<Item> items, string itemSeparator, string separator)
{
	string result;
	for (auto &item : items)
	{
		result += to_string(item.getId()) + separator + item.getTitle() +separator + item.getAuthor() + separator + item.getPublisher() + separator + item.getISBN() + separator + (item.isAvailable()? "yes" : "no");
		result += itemSeparator;
	}	
	return result;
}
string Serializer::serializeUsers(vector<User> users, string itemSeparator, string separator)
{
	string result;
	for (auto &user : users)
	{
		result += user.getId() + separator + user.getName() + separator + user.getAge() + separator + user.getEmail() + separator + user.getCreationDateTime();
		result += itemSeparator;
	}
	return result;
}