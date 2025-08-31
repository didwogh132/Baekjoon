#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int start;
	int end;
};
vector<node> arr;
bool cmp(node a, node b) {
	if (a.end < b.end) return true;
	if (a.end > b.end) return false;
	
	if (a.start < b.start) return true;
	if (a.start > b.start) return false;
	return false;
}
int cnt;
int num;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		arr.push_back({ s, e });
	}
	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < arr.size(); i++) {
		if (i == 0) {
			num = arr[i].end;
		}
		if (i != 0 && arr[i].start < num) {
			continue;
		}
		else {
			cnt++;
			num = arr[i].end;
		}
	}
	cout << cnt;


	return 0;
}