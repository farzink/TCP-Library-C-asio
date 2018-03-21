#ifndef LOGEER_H
#define LOGEER_H
#include <string>
#include "TermColor.hpp"
#include <iostream>
using namespace std;
class Logger {
public:
	void L1(string text, bool newline = true) {
		if (newline)
			cout << termcolor::on_white << termcolor::green << text << std::endl << termcolor::reset;
		else
			cout << termcolor::on_white << termcolor::green << text << termcolor::reset;
	}
	void L2(string text, bool newline = true) {
		if (newline)
			cout << termcolor::on_white << termcolor::red << text << std::endl << termcolor::reset;
		else
			cout << termcolor::on_white << termcolor::red << text << termcolor::reset;
	}

};
#endif
