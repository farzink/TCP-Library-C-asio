#include "stdafx.h"
#include "Item.hpp"


Item::Item(int id, string title, string author, string publisher, string isbn) {
	this->id = id;
	this->title = title;
	this->author = author;
	this->publisher = publisher;
	this->ISBN = isbn;
	this->availability = true;
}

int Item::getId() {
	return this->id;
}
string Item::getTitle() {
	return this->title;
}
string Item::getAuthor() {
	return this->author;
}
string Item::getPublisher() {
	return this->publisher;
}
string Item::getISBN() {
	return this->ISBN;
}
bool Item::isAvailable() {
	return this->availability;
}

void Item::setTitle(string title) {
	this->title = title;
}
void Item::setAuthor(string author) {
	this->author = author;
}
void Item::setPublisher(string publisher) {
	this->publisher = publisher;
}
void Item::setISBN(string isbn) {
	this->ISBN = isbn;
}
void Item::setAvailibility(bool availability) {
	this->availability = availability;
}
string Item::serializeToString(string separator)
{
	return to_string(this->getId()) + separator + this->getTitle() + separator + this->getAuthor() + separator + this->getPublisher() + separator + this->getISBN() + to_string(this->isAvailable());
}
Item Item::deserializeItem(vector<string> properties) {
	return Item(atoi(properties[0].c_str()), properties[1], properties[2], properties[3], properties[4]);
}