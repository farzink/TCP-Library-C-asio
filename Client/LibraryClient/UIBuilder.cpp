#include "stdafx.h"
#include "UIBuilder.hpp"
#include <iomanip>

string UIBuilder::selectItemForEdit(vector<vector<string>> items, string title, string extra)
{
	cout << termcolor::on_white << termcolor::red <<
		UIBuilder::repeater(32) + title + UIBuilder::repeater(32) << endl << termcolor::reset << endl;
	for (auto item : items)
	{
		cout << setw(2) << left << item[0] << termcolor::yellow << "|" << termcolor::reset;
		cout << setw(25) << left << item[1] << termcolor::white << "|" << termcolor::reset;
		cout << setw(18) << left << item[3] << termcolor::white << "|" << termcolor::reset;
		cout << setw(18) << left << item[2] << termcolor::white << "|" << termcolor::reset;
		cout << setw(7) << left << item[4] << termcolor::white << "|" << termcolor::reset;
		cout << setw(3) << left << ((item[5] == "yes") ? termcolor::green : termcolor::red) << item[5] << termcolor::reset << "|";
		cout << endl;
		cout << termcolor::yellow << UIBuilder::repeater(79) << termcolor::reset << endl;
	}
	cout << termcolor::on_white << termcolor::red << UIBuilder::repeater(79) << termcolor::reset << endl;
	if (extra != "")
		cout << extra;
	string itemId;
	getline(cin, itemId);
	return itemId;
}
void UIBuilder::showItems(vector<vector<string>> items, string title, string extra)
{
	cout << termcolor::on_white << termcolor::red <<
		UIBuilder::repeater(32)+ title + UIBuilder::repeater(32) << endl << termcolor::reset << endl;
	for (auto item : items)
	{
		cout << setw(2) << left << item[0] << termcolor::yellow << "|" << termcolor::reset;
		cout << setw(25) << left << item[1] << termcolor::white << "|" << termcolor::reset;
		cout << setw(18) << left << item[3] << termcolor::white << "|" << termcolor::reset;
		cout << setw(18) << left << item[2] << termcolor::white << "|" << termcolor::reset;
		cout << setw(7) << left << item[4] << termcolor::white << "|" << termcolor::reset;
		cout << setw(3) << left << ((item[5]=="yes")? termcolor::green : termcolor::red) << item[5] << termcolor::reset << "|";
		cout << endl;
		cout << termcolor::yellow << UIBuilder::repeater(79) << termcolor::reset << endl;		
	}
	cout << termcolor::on_white << termcolor::red << UIBuilder::repeater(79) << termcolor::reset << endl;
	if(extra != "")
	cout << extra;
}
void UIBuilder::showUsers(vector<vector<string>> users, string title, string extra)
{
	cout << termcolor::on_white << termcolor::red <<
		UIBuilder::repeater(32) + title + UIBuilder::repeater(32) << endl << termcolor::reset << endl;
	for (auto user : users)
	{
		cout << setw(2) << left << user[0] << termcolor::yellow << "|" << termcolor::reset;
		cout << setw(10) << left << user[1] << termcolor::white << "|" << termcolor::reset;
		cout << setw(30) << left << user[3] << termcolor::white << "|" << termcolor::reset;
		cout << setw(2) << left << user[2] << termcolor::white << "|" << termcolor::reset;
		cout << setw(10) << left << user[4] << termcolor::white << "|" << termcolor::reset;		
		cout << endl;
		cout << termcolor::yellow << UIBuilder::repeater(79) << termcolor::reset << endl;
	}
	cout << termcolor::on_white << termcolor::red << UIBuilder::repeater(79) << termcolor::reset << endl;
	if (extra != "")
		cout << extra;
}
string UIBuilder::repeater(int count, string block)
{
	string result;
	for (int i = 0; i < count; i++) {
		result += block;
	}
	return result;
}
void UIBuilder::showMenu(vector<string> menu)
{
	cout << termcolor::on_white << termcolor::yellow <<
		"------------------ M E N U -------------------" << endl << termcolor::reset;
	for (auto item : menu)
	{
		cout << item << endl;
	}
}
string UIBuilder::createItem() {
	cout << termcolor::on_white << termcolor::red <<
		UIBuilder::repeater(32) + "Item Creation" + UIBuilder::repeater(32) << endl << termcolor::reset << endl;
	string title, author, publisher, isbn;
	cout << "Title: ";
	getline(cin, title);
	cout << "Author: ";
	getline(cin, author);
	cout << "Publisher: ";
	getline(cin, publisher);
	cout << "ISBN: ";
	getline(cin, isbn);
	Item item(0, title, author, publisher, isbn);
	return item.serializeToString();
}
string UIBuilder::editItem(Item item) {
	cout << termcolor::on_white << termcolor::red <<
		UIBuilder::repeater(32) + "Item Edit" + UIBuilder::repeater(32) << endl << termcolor::reset << endl;
	string title, author, publisher, isbn;
	cout << "Title(current: " + item.getTitle() + ") -> new: ";
	getline(cin, title);
	cout << "Author(current: " + item.getAuthor() + ") -> new: ";
	getline(cin, author);
	cout << "Publisher(current: " + item.getPublisher() + ") -> new: ";
	getline(cin, publisher);
	cout << "ISBN(current: " + item.getISBN() + ") -> new: ";
	getline(cin, isbn);
	Item model(item.getId(), ((title=="") ? item.getTitle() : title),
		((author=="") ? item.getAuthor() : author),
		((publisher=="") ? item.getPublisher() : publisher),
		((isbn=="") ? item.getISBN() : isbn));
	return model.serializeToString();
}