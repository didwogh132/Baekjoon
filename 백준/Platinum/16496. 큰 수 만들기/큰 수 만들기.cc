#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	int n;
	cin >> n;

	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), cmp);

	if (arr[0] == "0") {
		cout << 0 << "\n";
	}
	else {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i];
		}
		cout << "\n";
	}

	return 0;
}