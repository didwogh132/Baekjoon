#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int y;
	int x;
};
vector<node> arr;

bool cmp(node a, node b) {
	if (a.x < b.x) return true;
	if (a.x > b.x) return false;

	if (a.y < b.y) return true;
	if (a.y > b.y) return false;

	return false;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int y, x;
		cin >> y >> x;
		arr.push_back({ y,x });
	}
	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].y << " " << arr[i].x << "\n";
	}

	return 0;
}