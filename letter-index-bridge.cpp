#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class LetterIndexBridge {
public:
	map<char, int> letterToIndex;
	map<int, char> indexToLetter;

	LetterIndexBridge() {
		string alphabet = "abcdefghijklmnopqrstuvwxyz";

		for (int i = 0; i < alphabet.size(); i++) {
			letterToIndex[alphabet[i]] = i;
			indexToLetter[i] = alphabet[i];
		}
	}
};