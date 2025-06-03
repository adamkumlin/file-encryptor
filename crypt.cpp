#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

class Crypt {
private:
	map<char, int> letterToIndex;
	map<int, char> indexToLetter;
	const char delimiter = '_';

	vector<string> formatRawLine(string line) {
		vector<string> indexes;
		stringstream stream(line);
		string splitString;

		while (getline(stream, splitString, delimiter)) {
			indexes.push_back(splitString);
		}

		return indexes;
	}

public:
	Crypt() {
		string alphabet = "abcdefghijklmnopqrstuvwxyz";

		for (int i = 0; i < alphabet.size(); i++) {
			letterToIndex[alphabet[i]] = i;
			indexToLetter[i] = alphabet[i];
		}
	}

	string encryptString(string phrase) {
		string encryptedIndexes;

		for (char c : phrase)
		{
			int letterIndex = letterToIndex.at(c);

			if (letterIndex + 4 > 25) {
				letterIndex += 4;
				int remainder = letterIndex - 25;
				letterIndex = remainder;
			}
			else {
				letterIndex += 4;
			}
			encryptedIndexes += to_string(letterIndex) + delimiter;
		}

		return encryptedIndexes;
	}

	string decryptString(string indexesRaw) {
		string decryptedString;
		vector<string> indexes = formatRawLine(indexesRaw);

		for (int i = 0; i < indexes.size(); i++) {
			int currentIndex = stoi(indexes[i]);
			if (currentIndex - 4 < 0) {
				currentIndex -= 4;
				int difference = 25 + currentIndex;
				currentIndex = difference;
			}
			else {
				currentIndex -= 4;
			}
			decryptedString += indexToLetter.at(currentIndex);
		}

		return decryptedString;
	}
};