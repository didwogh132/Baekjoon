#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<string> arr;

int main() {
	int x, y;
	int w, h;
	cin >> x >> y >> w >> h;
	int Min = 21e8;
	int Min1, Min2;

	if (x > w / 2 && y > h / 2) {
		Min1 = w - x;
		Min2 = h - y;
		if (Min1 > Min2) {
			Min = Min2;
		}
		else {
			Min = Min1;
		}
	}
	else if (x > w / 2 && y <= h / 2) {
		Min1 = w - x;
		Min2 = y - 0;
		if (Min1 > Min2) {
			Min = Min2;
		}
		else {
			Min = Min1;
		}
	}
	else if (x <= w / 2 && y > h / 2) {
		Min1 = x - 0;
		Min2 = h - y;
		if (Min1 > Min2) {
			Min = Min2;
		}
		else {
			Min = Min1;
		}
	}
	else {
		Min1 = x - 0;
		Min2 = y - 0;
		if (Min1 > Min2) {
			Min = Min2;
		}
		else {
			Min = Min1;
		}
	}
	cout << Min;
	return 0;
}