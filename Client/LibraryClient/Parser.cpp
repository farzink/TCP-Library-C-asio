#include "stdafx.h"
#include "Parser.hpp"
vector<vector<string>> Parser::parseItems(string context, string itemSeparator, string propertySeparator)
{	
	vector<string> parts;
	vector<vector<string>> items;
	if (context == "")
		return items;
	context.erase(context.end() - 1);
	boost::split(parts, context, boost::is_any_of(itemSeparator));
	for (auto item : parts) {
		vector<string> itemRow;
		boost::split(itemRow, item, boost::is_any_of(propertySeparator));
		items.push_back(itemRow);
	}
	return items;
}
vector<vector<string>> Parser::parseUsers(string context, string itemSeparator, string propertySeparator)
{	
	vector<string> parts;
	vector<vector<string>> users;
	if (context == "")
		return users;
	context.erase(context.end() - 1);
	boost::split(parts, context, boost::is_any_of(itemSeparator));
	for (auto item : parts) {
		vector<string> itemRow;
		boost::split(itemRow, item, boost::is_any_of(propertySeparator));
		users.push_back(itemRow);
	}
	return users;
}
vector<string> Parser::getMeta(string context)
{
	return Parser::split(Parser::split(context, "#")[0], ":");
}
string Parser::getOption(string context)
{
	return Parser::split(context, "#")[2];
}
string Parser::getCommand(string context)
{
	return Parser::split(Parser::split(context, "#")[1], ":")[0];	
}
string Parser::getPayload(string context)
{
	return Parser::split(Parser::split(context, "#")[1], ":")[1];
}
vector<string> Parser::parseItem(string context, string propertySeparator) {
	return Parser::split(context, propertySeparator);
}
string Parser::getContent(string context)
{
	return Parser::split(context, "#")[3];
}
vector<string> Parser::parseMenu(string context)
{
	return Parser::split(context, "~");
}
vector<string> Parser::split(string text, string separator)
{
	vector<string> parts;
	boost::split(parts, text, boost::is_any_of(separator));
	return parts;
}