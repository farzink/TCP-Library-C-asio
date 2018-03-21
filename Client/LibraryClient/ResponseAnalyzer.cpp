#include "stdafx.h"
#include "UIBuilder.hpp"
#include "ResponseAnalyzer.hpp"
#include "Parser.hpp"
string ResponseAnalyzer::preAnalyze(string response)
{
	auto meta = Parser::getMeta(response);	
	string command = Parser::getCommand(response);
	string option = Parser::getOption(response);
	return command;
}
vector<string> ResponseAnalyzer::getStatusMessage(string response)
{
	auto meta = Parser::getMeta(response);
	return meta;
}
ServerCommand ResponseAnalyzer::analyze(string response, string user)
{
	bool immediate = false;
	string command = Parser::getCommand(response);	
	string option = Parser::getOption(response);
	string payload = Parser::getPayload(response);
	if (command == "menu" && option=="-1") {
		UIBuilder::showMenu(Parser::parseMenu(Parser::getContent(response)));
	}
	else if (command == "menu" && option == "1") {
		UIBuilder::showItems(Parser::parseItems(Parser::getContent(response)), "Available Items");
	}
	else if (command == "menu" && option == "2") {
		UIBuilder::showItems(Parser::parseItems(Parser::getContent(response)), "   All Items   ");
	}
	else if (command == "menu" && option == "4") {
		UIBuilder::showItems(Parser::parseItems(Parser::getContent(response)), "   Borrowed Items   ");
	}
	else if (command == "menu" && option == "5") {
		UIBuilder::showUsers(Parser::parseUsers(Parser::getContent(response)), "   List of Users   ");
	}
	else if (command == "create") {
		command = command + ":" + UIBuilder::createItem();
	}
	else if (command == "reserve") {
		UIBuilder::showItems(Parser::parseItems(Parser::getContent(response)), "Available Items", "please enter the relevant item id: ");
	}
	else if (command == "introduce") {
		immediate = true;
		command = command + ":" + user;
	}
	else if (command == "edit") {
		if(option == "-1")
			command = command + "#" + UIBuilder::selectItemForEdit(Parser::parseItems(Parser::getContent(response)), "Item Edit", "please enter the relevant item id: ");
		if (option != "-1" && payload != "") {
			command = command + ":" + UIBuilder::editItem(Item::deserializeItem(Parser::parseItem(payload))) + "#" + option;
		}
		//command = command + ":" + UIBuilder::editItem();
	}
	return ServerCommand(command, immediate);
}