#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

struct node {
	int num;
	int cost;
};
vector<node> arr[1010];
int visited[1010];
int n, m;

void bfs(int num) {
	fill(visited, visited + n + 1, INT_MAX);
	queue<node> q;
	q.push({ num, 0 });
	visited[num] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		if (visited[now.num] < now.cost) continue;

		for (int i = 0; i < arr[now.num].size(); i++) {
			node next = arr[now.num][i];
			int nextcost = visited[now.num] + next.cost;
			if (visited[next.num] <= nextcost) continue;
			visited[next.num] = nextcost;
			q.push({ next.num, nextcost });
		}
	}
}


int main() {
	
	cin >> n >> m;
	

	for (int i = 0; i < n - 1; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to, cost });
		arr[to].push_back({ from, cost });
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		bfs(a);
		cout << visited[b] << "\n";
	}

	return 0;
}