#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n - 1; j++) {
			cout << " ";
		}
		for (int j = n - i; j < n + i + 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}