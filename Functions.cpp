#include <iostream>;
#include "Header.h";
using namespace std;

void print(string msg) {
	cout << msg << endl;
}
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
string stringUtil::append(string msg, string append) {
	return msg + append;
}
void stringUtil::prepend(string& msg1, string append) {
	msg1 = append + msg1;
}
string stringUtil::prepend(string msg1, string append) {
	return append + msg1;
}
void stringUtil::toUpper(string& msg) {
	for (char &i : msg) {
		if (i >= 'a' && i <= 'z') {
			i -= 32;
		}
	}
}
string stringUtil::toUpper(string msg) {
	for (char& i : msg) {
		if (i >= 'a' && i <= 'z') {
			i -= 32;
		}
	}
	return msg;
}
void stringUtil::toLower(string& msg) {
	for (char& i : msg) {
		if (i >= 'A' && i <= 'Z') {
			i += 32;
		}
	}
}
string stringUtil::toLower(string msg) {
	for (char& i : msg) {
		if (i >= 'A' && i <= 'Z') {
			i += 32;
		}
	}
	return msg;
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
