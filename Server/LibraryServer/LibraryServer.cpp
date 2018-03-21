// LibraryServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LibraryController.hpp"
using namespace std;




int main()
{	
	Context& context = Context::getInstance();
	LibraryController library(context);
	library.start();
    return 0;
}

