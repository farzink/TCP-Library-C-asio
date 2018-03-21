#ifndef USER_H
#define USER_H
#include <string>


using namespace std;

class User {
public:
	User(int, string, string, string);
	int getId();
	string getName();
	string getAge();
	string getEmail();

	void setName(string name);
	void setAge(string age);
	void setEmail(string email);
	User() {};
	~User() {};

protected:

private:
	int id;
	string name;
	string age;
	string email;
};

#endif
