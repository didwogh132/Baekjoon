#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	int arr[10] = { 0 };
	int dat[10] = { 0 };;
	int n;
	cin >> n;
	int a, b;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		if (dat[a] == 1 && arr[a] != b) cnt++;
		arr[a] = b;
		dat[a] = 1;
		
	}

	cout << cnt;
	return 0;
}