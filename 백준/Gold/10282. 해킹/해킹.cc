#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct node {
	int num;
	int cost;
	bool operator <(node right) const {
		if (cost < right.cost) return false;
		if (cost > right.cost)return true;
		return false;
	}
};
vector<node> arr[10010];
int dist[10010];
int n, d, c;
int cnt;
int Max;

void dijkstra(int start) {
	for (int i = 0; i <= n; i++) {
		dist[i] = 21e8;
	}
	priority_queue<node>pq;
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
			pq.push({ next.num, nextcost });
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cnt = 0;
		Max = 0;
		for (int i = 0; i <= n; i++) {
			arr[i].clear();
		}
		cin >> n >> d >> c;

		for (int i = 0; i < d; i++) {
			int from, to, cost;
			cin >> to >> from >> cost;
			arr[from].push_back({ to, cost });
		}
		dijkstra(c);

		for (int i = 0; i <= n; i++) {
			if (dist[i] != 21e8) {
				cnt++;
				if (dist[i] > Max) Max = dist[i];
			}
		}

		cout << cnt << " " << Max << "\n";

	}

	return 0;
}