#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string arr;
		int cnt = 0;
		cin >> arr;
		for (int j = 0; j < arr.size(); j++) {
			if (arr[j] == '(') {
				cnt++;
			}
			else {
				cnt--;
			}
			if (cnt < 0) {
				break;
			}
		}
		if (cnt < 0) {
			cout << "NO" << "\n";
		}
		else if(cnt > 0) {
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}
	}

	return 0;
}