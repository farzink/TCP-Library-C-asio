#include "stdafx.h"
#include "Item.hpp"


Item::Item(int id, string title, string author, string publisher, string isbn) {
	this->id = id;
	this->title = title;
	this->author = author;
	this->publisher = publisher;
	this -> ISBN = isbn;
	this->availability = true;
}
string Item::getOwner() {
	return this->owner;
}
void Item::setOwner(string owner) {
	this->owner == owner;
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