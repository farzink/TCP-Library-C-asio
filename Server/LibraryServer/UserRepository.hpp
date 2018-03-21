#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H
#include <string>
#include "Context.hpp"

using namespace std;

class UserRepository {
public:		
	bool userExist(string userId);
	bool insert(User user);
	vector<User> getAllUsers();
	
	UserRepository(Context&);
	~UserRepository() {};
protected:

private:
	Context& context;	
};

#endif
