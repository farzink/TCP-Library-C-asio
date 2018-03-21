#ifndef PARSER_H
#define PARSER_H
#include <boost\algorithm\string.hpp>
#include <vector>
#include <string>


using namespace std;
class Parser {
public:
	static vector<vector<string>> parseItems(string context, string itemSeparator = ";", string propertySeparator="|");
	static vector<vector<string>> parseUsers(string context, string itemSeparator = ";", string propertySeparator = "|");
	static vector<string> parseItem(string context, string propertySeparator = "|");
	static vector<string> getMeta(string context);
	static string getContent(string context);	
	static vector<string> parseMenu(string context);
	static string getOption(string context);
	static string getCommand(string context);
	static string getPayload(string context);
private:
	static vector<string> split(string text, string separator);
};
#endif