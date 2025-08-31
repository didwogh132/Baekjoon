#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

struct node {
	int num;
	int cost;
	bool operator <(node right) const {
		return cost > right.cost;
	}
};
int n, m, a, b, tax;
vector<node> arr[11];
int dist[11];
int visited[11];

bool dijkstra(int start, int limit) {
	for (int i = 1; i <= n; i++) {
		dist[i] = 21e8;
	}
	priority_queue<node> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dist[now.num] < now.cost) continue;

		for (int i = 0; i < arr[now.num].size(); i++) {
			node next = arr[now.num][i];
			if (next.cost > limit) continue;
			int nextcost = dist[now.num] + next.cost;
			if (dist[next.num] <= nextcost) continue;
			dist[next.num] = nextcost;
			visited[next.num] = now.num;
			pq.push({ next.num, nextcost });
		}
	}
	return dist[b] <= tax;
}


int main() {
	cin >> n >> m >> a >> b >> tax;
	int max_cost = 0;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to, cost });
		arr[to].push_back({ from, cost });
		max_cost = max(max_cost, cost);
	}

	int left = 0, right = max_cost, ans = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (dijkstra(a, mid)) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;

	return 0;
}