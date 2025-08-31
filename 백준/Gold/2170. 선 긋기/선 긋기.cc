#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct node {
	int from;
	int to;
};
bool cmp(node a, node b) {
	if (a.from < b.from) return true;
	if (a.from > b.from) return false;
	return false;
}
int n;
vector<node>arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		arr.push_back({ from, to });
	}
	sort(arr.begin(), arr.end(), cmp);

	int cur = arr[0].from;
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].from > cur) {
			cur = arr[i].from;
		}
		if(arr[i].to > cur) {
			sum += arr[i].to - cur;
			cur = arr[i].to;
		}
		//if (i == n-2 && arr[i + 1].from > cur) {
		//	cur = arr[i + 1].from;
		//}
	}
	cout << sum;

	return 0;
}
