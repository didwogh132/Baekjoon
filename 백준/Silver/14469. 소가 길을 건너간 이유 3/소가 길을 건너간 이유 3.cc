#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

struct node {
	int num;
	int cost;
};
bool cmp(node a, node b) {
	if (a.num < b.num) return true;
	if (a.num > b.num) return false;

	if (a.cost < b.cost) return true;
	if (a.cost > b.cost) return false;
}

int main() {
	int n;
	cin >> n;
	vector<node> arr;
	for (int i = 0; i < n; i++) {
		int num, cost;
		cin >> num >> cost;
		arr.push_back({ num, cost });
	}
	sort(arr.begin(), arr.end(), cmp);
	int cnt = 0;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].num > cnt) {
			cnt = arr[i].num + arr[i].cost;
		}
		else {
			cnt += arr[i].cost;
		}
	}

	cout << cnt;

	return 0;
}