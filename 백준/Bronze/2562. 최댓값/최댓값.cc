#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int main() {

	int arr[9];
	int Max = 0;
	int a;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 9; i++) {
		if (arr[i] > Max) {
			Max = arr[i];
			a = i + 1;
		}
	}

	cout << Max << "\n";
	cout << a;
	return 0;
}