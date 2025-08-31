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
		for (int j = n - i - 1; j < n; j++) {
			cout << "*";
		}
		for (int j = i + 1; j < n; j++) {
			cout << " ";
		}
		for (int j = i + 1; j < n; j++) {
			cout << " ";
		}
		for (int j = n - i - 1; j < n; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) {
			cout << "*";
		}
		for (int j = n - i; j < n; j++) {
			cout << " ";
		}
		for (int j = n - i; j < n; j++) {
			cout << " ";
		}
		for (int j = i; j < n; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}