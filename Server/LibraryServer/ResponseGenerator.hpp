#ifndef RESPONSEGENERATOR_H
#define RESPONSEGENERATOR_H
#include <string>
using namespace std;
class ResponseGenerator {
public:
	static string ResponseGenerator::BadRequest(string message, string text);
	static string ResponseGenerator::allItemsForEdit(string message);
	static string ResponseGenerator::Created(string message, string text);
	static string ResponseGenerator::Ok(string message, string text);
	static string menu();
	static string ResponseGenerator::allItems(string message);
	static string availableItems(string message);
	static string allReservedItems(string message);
	static string allUsers(string message);
};
#endif