#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int cnt;

int main() {
	int arr[6] = { 500, 100, 50, 10, 5, 1 };
	int n;
	cin >> n;
	n = 1000 - n;
	
	for (int i = 0; i < 6; i++) {
		while (n >= arr[i]) {
			n = n - arr[i];
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}