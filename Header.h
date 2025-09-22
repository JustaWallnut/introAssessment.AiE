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
		void prepend(string& msg1, string append);
		void toUpper(string& msg);
		void toLower(string& msg);
		int find(string msg, string findString);
		int find(int index, string msg, string findString);
		string replace(string msg, string findString, string replaceString);
		string ReadFromConsole();
		void WriteToConsole(string msg);
};
class stringTestUtil {
	public:
		void testLength();
		void testCharAt();
		void testEqualTo1();
		void testEqualTo2();
		void testAppend();
		void testPrepend();
		void testtoUpper();
		void testtoLower();
		void testFind1();
		void testFind2();
		void testReplace();
		void testReadFromConsole();
		void testWriteToConsole();
};
void runAllTests();