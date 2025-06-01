#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main()
{
	cout << "Welcome!\nPlease input the file path to start:\n";

	string filePath = "";
	bool isValidFilePath = false;
	while (!isValidFilePath) {
		cin >> filePath;
		if (filePath.length() > 0) {
			isValidFilePath = true;
		}
	}
	ifstream File(filePath);
	string fileLine;
	string fileContents;

	while (getline(File, fileLine)) {
		fileContents += fileLine + "\n";
	}
	cout << fileContents;

}

static void encryptString(string contents) {
	map<char, int> letters = {
		{'a', 0},
		{'b', 1},
		{'c', 2},
		{'d', 3},
		{'e', 4},
		{'f', 5},
		{'g', 6},
		{'h', 7},
		{'i', 8},
		{'j', 9},
		{'k', 10},
		{'l', 11},
		{'m', 12},
		{'n', 13},
		{'o', 14},
		{'p', 15},
		{'q', 16},
		{'r', 17},
		{'s', 18},
		{'t', 19},
		{'u', 20},
		{'v', 21},
		{'w', 22},
		{'x', 23},
		{'y', 24},
		{'z', 25}
	};

	string encrypted = "";

	for (int i = 0; i < contents.length(); i++)
	{
		char letter = contents[i];
		int letterIndex = letters.at(letter);

	}
}