#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cstring>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n - 1; j++) {
			cout << " ";
		}
		for (int j = n - 2 * i; j <= n; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = n; i > 0; i--) {
		for (int j = n - i + 1; j > 0; j--) {
			cout << " ";
		}
		for (int j = n - 2 * (i - 2); j <= n; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}