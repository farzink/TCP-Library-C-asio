#include "stdafx.h"
#include "User.hpp"
User::User(string id, string name, string age, string email) {
	this->id = id;
	this->name = name;
	this->age = age;
	this->email = email;
}
void User::setCreationDateTime(string creationDateTime) {
	this->creationDateTime = creationDateTime;
}
string User::getCreationDateTime() {
	return this->creationDateTime;
}
string User::getId() {
	return this->id;
}
string User::getName() {
	return this->name;
}
string User::getAge() {
	return this->age;
}
string User::getEmail() {
	return this->email;
}

void User::setName(string name) {
	this->name = name;
}
void User::setAge(string age) {
	this->age = age;
}
void User::setEmail(string email) {
	this->email = email;
}
