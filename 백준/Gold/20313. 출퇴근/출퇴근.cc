#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

int n, m, a, b, k;
struct node {
	int num;
	int k;
	long long cost;
	bool operator <(const node& right) const {
		return cost > right.cost;
	}
};
struct edge {
	int num;
	int idx;
	long long cost;
};
vector<int> k_dist;
vector<edge> arr[1010];
long long dist[101][1010];

void dijkstra(int num) {
	for (int i = 0; i <= k; i++) {
		fill(dist[i], dist[i] + n + 1, LLONG_MAX);
	}
	priority_queue<node> pq;
	pq.push({ num, 0, 0 });
	dist[0][num] = 0;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dist[now.k][now.num] < now.cost) continue;

		for (int i = 0; i < arr[now.num].size(); i++) {
			edge next = arr[now.num][i];
			long long nextcost = dist[now.k][now.num] + next.cost;
			if (now.k == k && k != 0) {
				nextcost = dist[now.k][now.num] + k_dist[next.idx];
				if (dist[now.k][next.num] <= nextcost) continue;
				dist[now.k][next.num] = nextcost;
				pq.push({ next.num, now.k, nextcost });
			}
			else if (now.k < k != 0) {
				if (dist[now.k][next.num] <= nextcost) continue;
				dist[now.k][next.num] = nextcost;
				pq.push({ next.num, now.k, nextcost });

				nextcost = dist[now.k][now.num] + k_dist[next.idx];
				if (dist[now.k + 1][next.num] <= nextcost) continue;
				dist[now.k + 1][next.num] = nextcost;
				pq.push({ next.num, now.k + 1, nextcost });
			}
			else if (k == 0) {
				if (dist[now.k][next.num] <= nextcost) continue;
				dist[now.k][next.num] = nextcost;
				pq.push({ next.num, now.k, nextcost });
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> a >> b;

	for (int i = 0; i < m; i++) {
		int from, to;
		long long cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to, i, cost });
		arr[to].push_back({ from, i, cost });
	}
	cin >> k;

	for (int i = 0; i < k; i++) {
		int cost_1, cost_2;
		cin >> cost_1 >> cost_2;
		k_dist.push_back(cost_2);
	}

	dijkstra(a);

	long long ans = LLONG_MAX;
	for (int i = 0; i <= k; i++) {
		ans = (dist[i][b] < ans) ? dist[i][b] : ans;
	}

	cout << ans;

	return 0;
}