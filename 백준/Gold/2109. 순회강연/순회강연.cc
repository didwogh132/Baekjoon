#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int pay;
	int day;
	bool operator<(node right) const {
		if (pay < right.pay) return true;
		if (pay > right.pay) return false;

		if (day < right.day) return false;
		if (day > right.day) return true;
		return false;
	}
};
struct node2 {
	int pay;
	int day;
};
vector<node2> arr;
priority_queue<node>pq;
bool cmp(node2 a, node2 b) {
	if (a.pay == b.pay) return a.day > b.day;
	return a.pay > b.pay;
}

int main() {
	int n;
	int arr2[100010];
	memset(arr2, 0, sizeof(arr2));
	cin >> n;
	for (int i = 0; i < n; i++) {
		int pay, day;
		cin >> pay >> day;
		arr.push_back({ pay, day });
	}
	sort(arr.begin(), arr.end(), cmp);
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i].day; j >= 1; j--) {
			if (arr2[j] == 0) {
				arr2[j] = arr[i].pay;
				res += arr2[j];
				break;
			}
		}
	}
	cout << res;

	return 0;
}