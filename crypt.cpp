#include <iostream>
#include <string>
#include <map>
using namespace std;

class Crypt {
private:
	map<char, int> letterToIndex;
	map<int, char> indexToLetter;

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
			encryptedIndexes += to_string(letterIndex) + "_";
		}

		return encryptedIndexes;
	}

	string decryptString(string indexes) {
		string decryptedString;

		for (char c : indexes) {
			int ic = (int)c;
			if (ic - 4 < 0) {
				ic -= 4;
				int difference = 25 + ic;
				ic = difference;
			}
			else {
				ic -= 4;
			}

			decryptedString += indexToLetter.at(ic);
		}
		return decryptedString;
	}
};