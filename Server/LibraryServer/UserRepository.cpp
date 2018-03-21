#include "stdafx.h"
#include "UserRepository.hpp"
#include "Context.hpp"
#include <algorithm>
#include <time.h>


UserRepository::UserRepository(Context &context) : context(context)
{
	this->context = context;
}
vector<User> UserRepository::getAllUsers() {
	return context.users;
}
bool UserRepository::userExist(string userId) {		
	for (auto &user : context.users)
	{
		if (user.getId() == userId)
		{
			return true;
		}
	}
	return false;
}
bool UserRepository::insert(User model)
{
	try {
		User user(model.getId(), model.getName(), model.getAge(), model.getEmail());
		time_t now = time(NULL);
		tm tlm;
		localtime_s(&tlm, &now);
		user.setCreationDateTime(to_string(tlm.tm_hour) + ":" + to_string(tlm.tm_min) + ":" + to_string(tlm.tm_sec));
		//delete the time pointer
		context.users.push_back(user);
		return true;
	}
	catch (exception ex) {
		return false;
	}
}