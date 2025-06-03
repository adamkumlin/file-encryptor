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
	string choiceInput;
	enum Operation {
		ENCRYPT,
		DECRYPT,
		UNSPECIFIED
	};
	Operation operation = UNSPECIFIED;

	std::cout << "Welcome!\nTo encrypt a file, press E.\nTo decrypt a file, press D.";

	while (operation == UNSPECIFIED) {
		std::cin >> choiceInput;
		if (choiceInput == "E" || choiceInput == "e") {
			operation = ENCRYPT;
		}
		else if (choiceInput == "D" || choiceInput == "d") {
			operation = DECRYPT;
		}
		else {
			std::cout << "Error: Invalid choice, try again.";
			operation = UNSPECIFIED;
		}
	}

	bool validFilePath = false;
	string filePath;
	while (!validFilePath) {
		std::cin >> filePath;

		if (filePath == "") {
			std::cout << "Error: File path is empty.";
			continue;
		}
	ifstream File(filePath);

	}

	string filePath = "";
	bool isValidFilePath = false;
	while (!isValidFilePath) {
		std::cin >> filePath;
		if (filePath.length() > 0) {
			isValidFilePath = true;
		}
		else {
			std::cout << "Error: Invalid file path.";
		}
	}
	ifstream File(filePath);
	string fileLine;
	vector<string> fileLines;

	while (getline(File, fileLine)) {
		fileLines.push_back(fileLine);
	}

	for (string line : fileLines) {

	}
	string encrypted = crypt.encryptString(fileLine);
	string decrypted = crypt.decryptString(encrypted);
	std::cout << encrypted << " : " << decrypted;
}

