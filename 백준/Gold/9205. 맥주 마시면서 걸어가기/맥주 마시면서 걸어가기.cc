#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
struct node {
	int y;
	int x;
	int num;
};
int n;
vector<node> arr;
bool cmp(node a, node b) {
	if (a.y + a.x < b.y + b.x) return true;
	if (a.y + a.x > b.y + b.x) return false;
	return false;
}
int visited[101];

void bfs(int y, int x) {
	queue<node> q;
	q.push({ y, x, 0 });
	visited[0] = 1;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i <= n; i++) {
			node next = arr[i];
			int dist = abs(now.y - next.y) + abs(now.x - next.x);
			if (dist > 1000) continue;
			if (visited[next.num] > -1) continue;
			visited[next.num] = visited[now.num] + 1;
			q.push({ next.y, next.x });
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		arr.clear();
		memset(visited, -1, sizeof(visited));
		cin >> n;
		int sy, sx;
		int ey, ex;
		cin >> sy >> sx;

		for (int i = 0; i < n; i++) {
			int y, x;
			cin >> y >> x;
			arr.push_back({ y,x, i + 1 });
		}
		sort(arr.begin(), arr.end(), cmp);
		cin >> ey >> ex;
		arr.push_back({ ey, ex, n + 1 });
		bfs(sy, sx);

		if (visited[n + 1] != -1) {
			cout << "happy" << "\n";
		}
		else {
			cout << "sad" << "\n";
		}
	}
	return 0;
}