#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int n, m, v;
vector<int>arr[1001];
int visited[1001];
int visited2[1001];
bool cmp(int a, int b ){
	return a < b;
}

void dfs(int now) {
	visited[now] = 1;
	cout << now << " ";
	for (int i = 0; i < arr[now].size(); i++) {
		int next = arr[now][i];
		if (visited[next] == 1) continue;
		visited[next] = 1;
		dfs(next);
	}
}

void bfs(int start) {
	queue<int>q;
	q.push(start);
	visited2[start] = 1;
	

	while (!q.empty()) {
		int now = q.front(); q.pop();
		
		cout << now << " ";
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			if (visited2[next] > 0) continue;
			visited2[next] = 1;
			q.push(next);
		}
	}
}

int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		arr[from].push_back(to);
		arr[to].push_back(from);
	}
	for (int i = 0; i <= n; i++) {
		sort(arr[i].begin(), arr[i].end());
	}

	dfs(v);
	cout << "\n";
	bfs(v);

	return 0;
}