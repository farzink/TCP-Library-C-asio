#include "stdafx.h"
#include "ResponseGenerator.hpp"
#include "Serializer.hpp"
string ResponseGenerator::menu() {
	string response = "unchanged:0#menu:#-1#";
	response += "1) List of available books~2) List of all books~3) Add new book~4) Show Borrowed books~5) Show Users~6) Edit book~0) Exit~-----------------------------\nplease select the corresponding number!";
	return response;
}
string ResponseGenerator::availableItems(string message) {
	string response = "unchanged:0#reserve:##";
	response += message;
	return response;
}
string ResponseGenerator::allReservedItems(string message) {
	string response = "unchanged:0#menu:#4#";
	response += message;
	return response;
}

string ResponseGenerator::BadRequest(string message, string text) {
	string response = message + ":1#";
	response += text;
	return response;
}
string ResponseGenerator::Created(string message, string text) {
	string response = message + ":2#";
	response += text;
	return response;
}
string ResponseGenerator::Ok(string message, string text) {
	string response = message + ":2#";
	response += text;
	return response;
}
string ResponseGenerator::allItems(string message) {
	string response = "unchanged:0#menu:#2#";
	response += message;
	return response;
}
string ResponseGenerator::allItemsForEdit(string message) {
	string response = "unchanged:0#edit:#-1#";
	response += message;
	return response;
}
string ResponseGenerator::allUsers(string message) {
	string response = "unchanged:0#menu:#5#";
	response += message;
	return response;
}