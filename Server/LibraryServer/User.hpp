#ifndef USER_H
#define USER_H
#include <string>


using namespace std;

class User {
public:
	User(string, string, string, string);	
	string getId();
	string getName();
	string getAge();
	string getEmail();	

	void setName(string name);
	void setAge(string age);
	void setEmail(string email);
	void setCreationDateTime(string creationDateTime);
	string getCreationDateTime();
	User() {};
	~User() {};

protected:

private:
	string id;
	string name;
	string age;
	string email;
	string creationDateTime;
};

#endif
