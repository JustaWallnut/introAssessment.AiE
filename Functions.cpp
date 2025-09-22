#include <iostream>;
#include "Header.h";
using namespace std;

void print(string msg) {
	cout << msg << endl;
}
#pragma region Assessment #1 Functions
int stringUtil::length(string msg) {
	int msgLength = 0;
	for (char i : msg) {
		msgLength++;
	}
	return msgLength;
}
char stringUtil::charAt(string msg, int index) {
	int msgLength = 0;
	for (char i : msg) {
		msgLength++;
	}
	if (index < 0 || index > msgLength) {
		return '\0';
	}
	else {
		return msg[index - 1];
	}
}
bool stringUtil::equalTo(string msg1, string msg2) {
	if (msg1 == msg2) {
		return true;
	}
	else {
		return false;
	}
}
void stringUtil::equalTo(string msg1, string msg2, string yesmsg, string nomsg) {
	if (msg1 == msg2) {
		print(yesmsg);
	}
	else {
		print(nomsg);
	}
}
void stringUtil::append(string& msg, string append) {
	msg = msg + append;
}
void stringUtil::prepend(string& msg1, string append) {
	msg1 = append + msg1;
}
void stringUtil::toUpper(string& msg) {
	for (char &i : msg) {
		if (i >= 'a' && i <= 'z') {
			i -= 32;
		}
	}
}
void stringUtil::toLower(string& msg) {
	for (char& i : msg) {
		if (i >= 'A' && i <= 'Z') {
			i += 32;
		}
	}
}
int stringUtil::find(string msg, string findString) {
	int msgLength = 0;
	int findLength = 0;
	for (char i : msg) {
		msgLength++;
	}
	for (char i : findString) {
		findLength++;
	}
	if (findLength > msgLength) {
		return -1;
	}
	else {
		// Goes through every character of msg and checks with the first character of findString
		// If it finds a common character, it does repeated checks with the further characters
		// if it all connects, break the loop and return the location its found
		int location;
		for (int i = 0; i <= msgLength - findLength; i++) {
			if (msg[i] == findString[0]) {
				location = i;
				bool found = false;
				for (int a = 1; a <= findLength; a++) {
					if (a == findLength) {
						return location + 1;
					}
					if (!(msg[i + a] == findString[0 + a])) {
						break;
					}
				}
			}
		}
		return -1;
	}
}
int stringUtil::find(int index, string msg, string findString) {
	int msgLength = 0;
	int findLength = 0;
	for (char i : msg) {
		msgLength++;
	}
	for (char i : findString) {
		findLength++;
	}
	if (findLength > msgLength) {
		return -1;
	}
	else {
		// Goes through every character of msg and checks with the first character of findString
		// If it finds a common character, it does repeated checks with the further characters
		// if it all connects, break the loop and return the location its found
		int location;
		for (int i = index; i <= msgLength - findLength; i++) {
			if (msg[i] == findString[0]) {
				location = i;
				bool found = false;
				for (int a = 1; a <= findLength; a++) {
					if (a == findLength) {
						return location + 1;
					}
					if (!(msg[i + a] == findString[0 + a])) {
						break;
					}
				}
			}
		}
		return -1;
	}
}
// Currently non-functional
//string stringUtil::replace(string msg, string findString, string replaceString) {
//	int msgLength = 0;
//	int findLength = 0;
//	int replaceLength = 0;
//	for (char i : msg) {
//		msgLength++;
//	}
//	for (char i : findString) {
//		findLength++;
//	}
//	for (char i : replaceString) {
//		replaceLength++;
//	}
//	if (findLength > msgLength) {
//		return "-1";
//	}
//	else {
//		// Goes through every character of msg and checks with the first character of findString
//		// If it finds a common character, it does repeated checks with the further characters
//		// if it all connects, start replacing strings, then goes back to checking
//		int location = 0;
//		bool found = false;
//		for (int i = 0; i <= msgLength - findLength; i++) {
//			if (msg[i] == findString[0]) {
//				location = i;
//				for (int a = 1; a <= findLength; a++) {
//					if (a == findLength) {
//						if (findLength < replaceLength) {
//							string tempMsg = msg;
//							string newMsg = "";
//							int e = 0;
//							for (int c = 0; c <= msgLength - findLength + replaceLength; c++) {
//								if (c == location) {
//									for (int f = 0; f <= replaceLength; f++, c++) {
//										newMsg += replaceString[f];
//									}
//									e += findLength;
//									c -= 1;
//									// programmers will see this code and kill themselves
//								}
//								else {
//									newMsg += tempMsg[e];
//									e += 1;
//								}
//							}
//							msg = newMsg;
//						}
//						else if (findLength == replaceLength) {
//							for (int b = 0; b <= findLength; b++) {
//								msg[i + b] = replaceString[b];
//							}
//						}
//						else {
//
//						}
//						found = true;
//						if (!(msg[i + a] == findString[0 + a])) {
//							break;
//						}
//					}
//				}
//			}
//		}
//		if (!found) { return "-1"; }
//	}
//}
//string stringUtil::replace(string msg, string findString, string replaceString) {
//	// You were manually counting string lengths, instead of using .length(). Should save some time.
//	int msgLength = msg.length();
//	int findLength = findString.length();
//	int replaceLength = replaceString.length();
//
//	if (findLength > msgLength) {
//		return "-1";
//	}
//	else {
//		// Goes through every character of msg and checks with the first character of findString
//		// If it finds a common character, it does repeated checks with the further characters
//		// if it all connects, start replacing strings, then goes back to checking
//		int location = 0;
//		bool found = false;
//		for (int i = 0; i <= msgLength - findLength; i++) {
//			if (msg[i] == findString[0]) {
//				for (int a = 0; a <= findLength; a++) {
//					if (a == findLength - 1)
//					{
//						// If whatever you're gonna replace it with is longer than the original
//						if (findLength < replaceLength) {
//							string tempMsg = msg;
//							string newMsg = "";
//							int e = 0;
//							for (int c = 0; c <= msgLength - findLength + replaceLength; c++) {
//
//								if (c == location) {
//									for (int f = 0; f < replaceLength; f++, c++) {
//										newMsg += replaceString[f];
//									}
//									e += findLength;
//									c -= 1;
//									// programmers will see this code and kill themselves
//								}
//								else {
//									newMsg += tempMsg[e];
//									e += 1;
//								}
//							}
//							msg = newMsg;
//						}
//						else if (findLength == replaceLength) {
//							for (int b = 0; b < findLength; b++) {
//								msg[i + b] = replaceString[b];
//							}
//							return msg;
//						}
//						else {
//
//						}
//						found = true;
//						if (!(msg[i + a] == findString[0 + a])) {
//							break;
//						}
//					}
//				}
//			}
//
//		}
//		if (!found) { return "-1"; }
//	}
//}
string stringUtil::ReadFromConsole() {
	string input = "";
	cin >> input;
	return input;
}
void stringUtil::WriteToConsole(string msg) {
	print(msg);
}
#pragma endregion
#pragma region Assessment #2 Functions
void stringTestUtil::testLength() {
	string testMessage = "bongbong";
	stringUtil Test;
	int length = Test.length(testMessage);
	if (length == 8) {
		cout << "OPERATIONAL";
	}
	else {
		cout << "DYSFUNCTIONAL";
	}
	print(" --- PRINT FUNCTION");
}
void stringTestUtil::testCharAt() {
	string testMessage = "yumyum";
	stringUtil Test;
	int characterAt = Test.charAt(testMessage, 4);
	if (characterAt == 'y') {
		cout << "OPERATIONAL";
	}
	else {
		cout << "DYSFUNCTIONAL";
	}
	print(" --- CHARACTER-AT FUNCTION");
}
void stringTestUtil::testEqualTo1() {
	string testMessage1 = "bongbong";
	string testMessage2 = "yumyum";
	stringUtil Test;
	if (!(Test.equalTo(testMessage1, testMessage2))) {
		cout << "OPERATIONAL";
	}
	else {
		cout << "DYSFUNCTIONAL";
	}
	print(" --- STRING-EQUALTO FUNCTION");
}
void stringTestUtil::testEqualTo2() {
	string testMessage1 = "bongbong";
	string testMessage2 = "yumyum";
	stringUtil Test;
	Test.equalTo(testMessage1, testMessage2, "Hello!", "Goodbye!");
	print("OPERATIONAL if printed Goodbye! Else, DYSFUNCTIONAL --- VOID-EQUALTO FUNCTION");
}
void stringTestUtil::testAppend() {
	string testMessage1 = "bongbong";
	string testMessage2 = "yumyum";
	stringUtil Test;
	Test.append(testMessage1, testMessage2);
	if (testMessage1 == "bongbongyumyum") {
		cout << "OPERATIONAL";
	}
	else {
		cout << "DYSFUNCTIONAL";
	}
	print(" --- APPEND FUNCTION");
}
void stringTestUtil::testPrepend() {
	string testMessage1 = "bongbong";
	string testMessage2 = "yumyum";
	stringUtil Test;
	Test.prepend(testMessage1, testMessage2);
	if (testMessage1 == "yumyumbongbong") {
		cout << "OPERATIONAL";
	}
	else {
		cout << "DYSFUNCTIONAL";
	}
	print(" --- PREPEND FUNCTION");
}
void stringTestUtil::testtoUpper() {
	string testMessage = "BonGbONggG";
	stringUtil Test;
	Test.toUpper(testMessage);
	if (testMessage == "BONGBONGGG") {
		cout << "OPERATIONAL";
	}
	else {
		cout << "DYSFUNCTIONAL";
	}
	print(" --- UPPERCASE FUNCTION");
}
void stringTestUtil::testtoLower() {
	string testMessage = "BonGbONggG";
	stringUtil Test;
	Test.toLower(testMessage);
	if (testMessage == "bongbonggg") {
		cout << "OPERATIONAL";
	}
	else {
		cout << "DYSFUNCTIONAL";
	}
	print(" --- LOWERCASE FUNCTION");
}
void stringTestUtil::testFind1() {
	string testMessage = "Wingding";
	string targetMessage = "ding";
	stringUtil Test;
	if (Test.find(testMessage, targetMessage) == 5) {
		cout << "OPERATIONAL";
	}
	else {
		cout << "DYSFUNCTIONAL";
	}
	print(" --- FIND FUNCTION");
}
void stringTestUtil::testFind2() {
	string testMessage = "DookWardingDook";
	string targetMessage = "Dook";
	int index = 6;
	stringUtil Test;
	if (Test.find(index, testMessage, targetMessage) == 12) {
		cout << "OPERATIONAL";
	}
	else {
		cout << "DYSFUNCTIONAL";
	}
	print(" --- FIND-INDEX FUNCTION");
}
void stringTestUtil::testReplace() {
	string testMessage = "wingwongbongboom";
	string testFind = "bong";
	string testReplace = "yummer";
	stringUtil Test;
	if (Test.replace(testMessage, testFind, testReplace) == "wingwongyummerboom") {
		cout << "OPERATIONAL";
	}
	else {
		cout << "DYSFUNCTIONAL";
	}
	print(" --- REPLACE FUNCTION");
}
void stringTestUtil::testReadFromConsole() {
	string Input;
	stringUtil Test;
	Input = Test.ReadFromConsole();
	print(Input);
	print("OPERATIONAL if printed correctly! Else, DYSFUNCTIONAL --- READFROMCONSOLE FUNCTION");
}
void stringTestUtil::testWriteToConsole() {
	print("TESTING OPERATION OF THE WRITETOCONSOLE FUNCTION ---");
	string message = "If you see this message, the functiton is OPERATIONAL!";
	stringUtil Test;
	Test.WriteToConsole(message);
}
void runAllTests() {
	stringTestUtil Test;
	Test.testLength();
	Test.testCharAt();
	Test.testEqualTo1();
	Test.testEqualTo2();
	Test.testAppend();
	Test.testPrepend();
	Test.testtoUpper();
	Test.testtoLower();
	Test.testFind1();
	Test.testFind2();
	Test.testReplace();
	Test.testReadFromConsole();
	Test.testWriteToConsole();
}
#pragma endregion
