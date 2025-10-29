#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
struct node {
	int s;
	int e;
};

bool cmp(node a, node b) {
	if (a.e != b.e) return a.e < b.e;
	else a.s > b.s;
}
vector<node> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		arr.push_back({ s, e });
	}

	sort(arr.begin(), arr.end(), cmp);

	int ans = 10000000;
	bool flag = true;

	int time = 0;
	for (int i = 0; i < n; i++) {
		time += arr[i].s;
		int min;
		if (time > arr[i].e) {
			flag = false;
			break;
		}
		else {
			min = arr[i].e - time;
			if (min < ans) ans = min;
		}
	}

	if (flag) cout << ans;
	else cout << -1;

	return 0;
}