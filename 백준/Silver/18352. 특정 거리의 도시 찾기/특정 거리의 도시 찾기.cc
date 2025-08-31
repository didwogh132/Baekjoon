#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int num;
	int cost;
	bool operator<(node right) const {
		return cost > right.cost;
	}
};
vector<node> arr[300010];
int cnt;
int dist[300010];
int dist_cnt[300010];
int n, m, k, x;

void dijkstra(int start) {
	for (int i = 0; i <= n; i++) {
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
			int nextcost = dist[now.num] + next.cost;
			if (dist[next.num] <= nextcost) continue;
			dist[next.num] = nextcost;
			if (dist[next.num] == k) {
				dist_cnt[cnt] = next.num;
				cnt++;
			}
			pq.push({ next.num, nextcost });
		}
	}
}


int main() {
	
	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to;
		arr[from].push_back({ to, 1 });
	}
	dijkstra(x);

	sort(dist_cnt, dist_cnt + cnt);

	if (cnt == 0) {
		cout << -1;
	}
	else {
		for (int i = 0; i < cnt; i++) {
			cout << dist_cnt[i] << "\n";
		}
	}
	return 0;
}