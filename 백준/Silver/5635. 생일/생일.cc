#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct node {
	string name;
	int day;
	int month;
	int year;
};
bool cmp(node a, node b) {
	if (a.year < b.year) return true;
	if (a.year > b.year) return false;

	if (a.month < b.month) return true;
	if (a.month > b.month) return false;

	if (a.day < b.day) return true;
	if (a.day > b.day) return false;

	return false;
}

int main() {
	node arr[101];

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].name >> arr[i].day >> arr[i].month >> arr[i].year;
	}
	sort(arr, arr + n, cmp);

	cout << arr[n - 1].name << "\n";
	cout << arr[0].name;

	return 0;
}