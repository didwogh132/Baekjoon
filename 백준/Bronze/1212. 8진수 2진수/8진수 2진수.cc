#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
	int len;
	char eight[333335];
	char first[10][4] = {
		"",
		"1",
		"10",
		"11",
		"100",
		"101",
		"110",
		"111"
	};
	char table[10][4] = { "000", "001", "010","011", "100", "101", "110", "111" };
	cin >> eight;
	len = strlen(eight);
	if (eight[0] == '0') {
		cout << 0;
	}
	else {
		cout << first[eight[0] - '0'];

		for (int i = 1; i < len; i++) {
			cout << table[eight[i] - '0'];
		}
	}

	return 0;
}