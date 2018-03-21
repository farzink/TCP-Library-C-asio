#ifndef SERIALIZER_H
#define SERIALIZER_H
#include <vector>
#include <string>
#include "Item.hpp"
#include "User.hpp"

using namespace std;
class Serializer {
public:
	static string serializeItem(Item item, string separator="|");
	static string serializeItems(vector<Item> items, string itemSeparator = ";", string separator = "|");
	static string serializeUsers(vector<User> users, string itemSeparator = ";", string separator = "|");
	static Item deserializeItem(string content, string separator = "|");
	static User deserializeUser(string content, string separator="|");
};
#endif