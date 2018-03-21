#ifndef RESPONSEANALYZER_H
#define RESPONSEANALYZER_H
#include <boost\algorithm\string.hpp>
#include <vector>
#include <string>
#include "ServerCommand.hpp"


using namespace std;
class ResponseAnalyzer {
public:
	string preAnalyze(string response);
	ServerCommand analyze(string response, string user);
	vector<string> getStatusMessage(string response);
};
#endif