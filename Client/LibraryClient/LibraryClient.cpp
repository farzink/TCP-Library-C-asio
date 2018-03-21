#include "stdafx.h"
#include <string>
#include <boost/asio.hpp>
#include <iostream>
#include "ClientManager.hpp"
using namespace std;
namespace asio = boost::asio;

int main() {	
	ClientManager manager;
	manager.run();
	return 0;
}