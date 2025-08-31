#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;

struct node {
	int num;
	long long cost;
};
vector<node>arr[101];
long long visited[101];

void bfs(int num) {
	queue<node> q;
	q.push({ num, 0 });
	visited[num] = 0;
	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < arr[now.num].size(); i++) {
			node next = arr[now.num][i];
			int nextcost = visited[now.num] + next.cost;
			if (visited[next.num] > nextcost) {
				visited[next.num] = nextcost;
			}
			else if (visited[next.num] > -1) continue;
			else {
				visited[next.num] = nextcost;
			}
			q.push({ next.num, nextcost });
		}
	}
}
int main() {
	int n;
	int m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to;
		long long cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to, cost });
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, -1, sizeof(visited));
		bfs(i);

		for (int j = 1; j <= n; j++) {
			if (visited[j] == -1) {
				cout << 0 << " ";
			}
			else {
				cout << visited[j] << " ";
			}
		}
		cout << "\n";
	}
}