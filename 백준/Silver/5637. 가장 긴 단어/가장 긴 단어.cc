#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

string cleanWord(string word) {
	string result;
	for (int i = 0; i < word.size(); i++) {
		if (isalpha(word[i]) || word[i] == '-') {
			result += tolower(word[i]);
		}
	}
	return result;
}

int main() {

	string arr;
	string longword = "";
	while (true) {
		cin >> arr;
		if (arr == "E-N-D") break;
		string cleanword = cleanWord(arr);
		if (cleanword.size() > longword.size()) {
			longword = cleanword;
		}
	}

	cout << longword;

	return 0;
}