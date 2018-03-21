#include "stdafx.h"
#include <boost\algorithm\string.hpp>
#include "CommandDispather.hpp"
#include "Serializer.hpp"
#include <string>
#include <vector>
#include "ResponseGenerator.hpp"




string CommandDispatcher::interpret(string command)
{
	vector<string> parts;
	vector<string> commandSection;
	boost::split(parts, command, boost::is_any_of("#"))[1];
	boost::split(commandSection, parts[1], boost::is_any_of(":"));
	string client = parts[0];
	string com = commandSection[0];
	string payload;

	if (!userRepository.userExist(client) && com != "introduce") {
		return ResponseGenerator::Ok("unchanged:introduce yourself!:0", "introduce:##");
	}


	if (commandSection.size() > 1)
		payload = commandSection[1];
	if (com == "start") {
		return ResponseGenerator::menu();
	}
	else if (com == "introduce") {
		this->userRepository.insert(Serializer::deserializeUser(payload));
		return ResponseGenerator::Created("client successfully registered.", "start:#-1#");
	}
	else if (com == "menu") {
#pragma region MENU
		int option = std::stoi(parts[2]);
		if (option < 0 || option >6)
			return ResponseGenerator::menu();
		if (option == 1)
		{
			string result = ResponseGenerator::availableItems(Serializer::serializeItems(itemRepository.getAllAvailableItems()));
			return result;
		}
		else if (option == 2)
		{
			string result = ResponseGenerator::allItems(Serializer::serializeItems(itemRepository.getAllItems()));
			return result;
		}
		else if (option == 4)
		{
			string result = ResponseGenerator::allReservedItems(Serializer::serializeItems(itemRepository.getAllReservedItems()));
			if (result == "unchanged:0#menu#4#")
				return ResponseGenerator::BadRequest("no item has borrowed yet!", "start:#-1#");
			return result;
		}
		else if (option == 3) {
			return ResponseGenerator::Ok("unchanged:request to add:0", "create:##");
		}
		else if (option == 5) {
			string result = ResponseGenerator::allUsers(Serializer::serializeUsers(userRepository.getAllUsers()));
			return result;
		}
		else if (option == 6) {
			string result = ResponseGenerator::allItemsForEdit(Serializer::serializeItems(itemRepository.getAllItems()));
			return result;
		}
#pragma endregion	    
	}
	else if (com == "reserve") {
#pragma region Reserve
		try {
			int option = std::stoi(parts[2]);
			if (option == 0)
				return ResponseGenerator::menu();
			if (itemRepository.getItemById(option) == NULL) {
				return ResponseGenerator::BadRequest("the requested id doest exist", "start:#-1#");
			}
			auto status = itemRepository.reserveItem(option);
			if (status) {
				return ResponseGenerator::Created("item successfully borrowed", "start:#-1#");
			}
			else {
				return ResponseGenerator::BadRequest("item can`t be barrowed as it is already borrowed!", "start:#-1#");
			}
		}
		catch (exception ex) {
			return ResponseGenerator::BadRequest("wrong id format, only integers", "start:#-1#");
		}
#pragma endregion
	}
	else if (com == "create") {
		if (payload == "")
			return ResponseGenerator::BadRequest("something wrong happend, please try again!", "start:#-1#");
		if (itemRepository.insert(Serializer::deserializeItem(payload)))
			return ResponseGenerator::Ok("item successfully created", "start:#-1#");
		return ResponseGenerator::BadRequest("something wrong happend, please try again!", "start:#-1#");
	}
	else if (com == "edit") {
		int option = std::stoi(parts[2]);
		if (option == -1)
			return ResponseGenerator::BadRequest("wrong id format, only integers", "start:#-1#");
		else {
			if (payload == "") {
				auto item = itemRepository.getItemById(option);
				if (item == NULL)
					return ResponseGenerator::BadRequest("wrong id format, only integers", "start:#-1#");
				return ResponseGenerator::Ok("unchanged", "edit:" + Serializer::serializeItem(*item) + "#" + to_string(item->getId()));
			}
			else {
				//final edit
				if (!itemRepository.update(Serializer::deserializeItem(payload))) {
					return ResponseGenerator::BadRequest("something wrong happend, please try again!", "start:#-1#");
				}
				return ResponseGenerator::Ok("item successfully updated!", "start:#-1#");
			}
		}

	}
	else {
		return "unknown";
	}
}