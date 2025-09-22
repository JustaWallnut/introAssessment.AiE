#pragma once
#include <iostream>;
using namespace std;

void print(string msg);
class stringUtil {
public:
	int length(string msg);
	char charAt(string msg, int index);
	bool equalTo(string msg1, string msg2);
	void equalTo(string msg1, string msg2, string yesmsg, string nomsg);
	void append(string& msg, string append);
	string append(string msg, string append);
	void prepend(string& msg1, string append);
	string prepend(string msg1, string append);
	void toUpper(string& msg);
	string toUpper(string msg);
	void toLower(string& msg);
	string toLower(string msg);
	int find(string msg, string findString);
	int find(int index, string msg, string findString);
	string replace(string msg, string findString, string replaceString);
	string ReadFromConsole();
	void WriteToConsole(string msg);
};