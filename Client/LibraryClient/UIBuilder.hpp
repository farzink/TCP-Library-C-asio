#ifndef UIBUILDER_H
#define UIBUILDER_H
#include "TermColor.hpp"
#include <boost\algorithm\string.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Item.hpp"


using namespace std;
class UIBuilder {
private:
	static string repeater(int count, string block="-");
public:
	static void showMenu(vector<string> menu);
	static string editItem(Item item);
	static void showItems(vector<vector<string>>items, string title="title", string extra="");
	static string selectItemForEdit(vector<vector<string>> items, string title="title", string extra="");
	static void showUsers(vector<vector<string>> users, string title, string extra="");
	static string createItem();
};
#endif