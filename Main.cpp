#include <iostream>;
#include "Header.h";
using namespace std;

int main() {
	stringUtil stringFunc;
	cout << stringFunc.length("Damn Uhh") << endl;
	cout << stringFunc.charAt("Dooper", 4) << endl;
	stringFunc.equalTo("wingwong", "bingbong", "Haha", "No.");
	cout << stringFunc.append("Dooper", "Goober") << endl;
	cout << stringFunc.toUpper("weesDD") << endl;
	cout << stringFunc.toLower("weasSSmSWomp") << endl;
	cout << stringFunc.find("wewewasddido", "do") << endl;
}