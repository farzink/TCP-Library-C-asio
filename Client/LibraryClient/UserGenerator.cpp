#include "stdafx.h"
#include "UserGenerator.hpp"
string UserGenerator::serializeUser(User user, string separator) {
	return  to_string(user.getId()) + separator + user.getName() + separator + user.getAge() + separator + user.getEmail();
}

User UserGenerator::getRandomUser() {
	int id = rand() % 100000 + 44444;
	string name = this->names[((rand() % sizeof(this->names) / sizeof(*this->names)))];
	string age = this->ages[((rand() % sizeof(this->ages) / sizeof(*this->ages)))];
	string email = name + "@fhkiel-library.de";
	User user(id, name, age, email);
	return user;
};