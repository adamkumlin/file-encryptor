#include <iostream>
#include <fstream>
#include <string>
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

}