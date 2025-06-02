#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "crypt.cpp"
using namespace std;

Crypt crypt;

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
		else {
			cout << "Error: Invalid file path.";
		}
	}
	ifstream File(filePath);
	string fileLine;
	vector<string> fileLines;

	while (getline(File, fileLine)) {
		fileLines.push_back(fileLine);
	}

	string encrypted = crypt.encryptString(fileLine);
	cout << encrypted;

}

