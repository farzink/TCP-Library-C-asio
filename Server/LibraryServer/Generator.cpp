#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>     
#include <time.h>
#include <vector>
#include "Generator.hpp"
#include "Item.hpp"
#include "User.hpp"


/* generate secret number between 1 and 10: */
//iSecret = rand() % 10 + 1;

vector<Item> Generator::generateItems(int size)
{	
	vector<Item> items;
	for(int i = 0; i < size; i++) {
		Item item = Item(this->getNextId(), this->getRandomCompleteTitle(), this->getRandomAuthor(), this->getRandomPublisher(), this->getRandomISBN());
		items.push_back(item);
	}
	return items;
}
string Generator::getRandomCompleteTitle(){
	int behavior = (rand() % 3) + 1;
	if (behavior == 1) {
		string preTitle = this->getRandomPreTitle();
		string title = this->getRandomTitle();
		return preTitle + " " + title;
	}
	else if (behavior == 2) {
		string title = this->getRandomTitle();
		string postTitle = this->getRandomPostTitle();
		return title + " " + postTitle;
	}
	else {
		return this->getRandomTitle();
	}
}
int Generator::getNextId() {
	this->id++;
	return this->id;
}
string Generator::getRandomTitle() {
	return this->titles[((rand() % sizeof(this->titles)/sizeof(*this->titles)))];
}
string Generator::getRandomPreTitle() {
	return this->preTitles[((rand() % sizeof(this->preTitles)/sizeof(*this->preTitles)))];
}
string Generator::getRandomPostTitle() {
	return this->postTitles[((rand() % sizeof(this->postTitles)/sizeof(*this->postTitles)))];
}
string Generator::getRandomAuthor() {
	return this->authors[((rand() % sizeof(this->authors)/sizeof(*this->authors)))];
}
string Generator::getRandomPublisher() {
	return this->publishers[((rand() % sizeof(this->publishers)/sizeof(*this->publishers)))];
}
string Generator::getRandomISBN() {
	return to_string(rand() % 10000000 + 1000000);
}


