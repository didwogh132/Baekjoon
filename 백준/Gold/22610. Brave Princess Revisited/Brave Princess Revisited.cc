#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

int n, m, l;
struct node {
	int num;
	int line;
	int cost;
	bool operator<(const node& right) const {
		return cost > right.cost;
	}
};
int dist[101][101];
vector<node> arr[101];
int ans;

void dijkstra(int num) {
	priority_queue<node> pq;
	pq.push({ num, 0, 0 });
	dist[0][num] = 0;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dist[now.line][now.num] < now.cost) continue;
		if (now.num == n) {
			ans = (dist[now.line][now.num] < ans) ? dist[now.line][now.num] : ans;
			continue;
		}

		for (int i = 0; i < arr[now.num].size(); i++) {
			node next = arr[now.num][i];
			int nextcost = now.cost + next.cost;
			int nextline = now.line;
			if (dist[nextline][next.num] > nextcost) {
				dist[nextline][next.num] = nextcost;
				pq.push({ next.num, nextline, nextcost });
			}

			if (now.line + next.line <= l) {
				int guardline = now.line + next.line;
				int guardcost = now.cost;
				if (dist[guardline][next.num] > guardcost) {
					dist[guardline][next.num] = guardcost;
					pq.push({ next.num, guardline, guardcost });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		ans = INT_MAX;
		cin >> n >> m >> l;

		if (n == 0 && m == 0 && l == 0) break;

		for (int i = 0; i <= l; i++) {
			fill(dist[i], dist[i] + n + 1, INT_MAX);
		}

		for (int i = 0; i < m; i++) {
			int from, to, line, cost;
			cin >> from >> to >> line >> cost;
			arr[from].push_back({ to, line, cost });
			arr[to].push_back({ from, line, cost });
		}

		dijkstra(1);

		for (int i = 0; i <= n; i++) {
			arr[i].clear();
		}

		cout << ans << "\n";
	}

	return 0;
}