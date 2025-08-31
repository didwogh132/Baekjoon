#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int main() {

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int r;
		string s;
		cin >> r >> s;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < r; j++) {
				cout << s[i];
			}
		}
		cout << "\n";
	}

	return 0;
}