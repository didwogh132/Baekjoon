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
	for (int i = 0; i < t; i++) {
		char arr[3];
		for (int i = 0; i < 3; i++) {
			cin >> arr[i];
		}

		cout << (int)(arr[0] - '0') + (int)(arr[2] - '0') << "\n";
	}

	return 0;
}