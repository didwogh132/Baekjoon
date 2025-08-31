#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct node {
	int num;
	int cost;
	bool operator<(node right) const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;
		return false;
	}
};
vector<node> arr[1010];
int dist[1010];
int dist2[1010];
int n, m, x;
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
		for (int i = 0;i < arr[now.num].size(); i++) {
			node next = arr[now.num][i];
			int nextcost = dist[now.num] + next.cost;

			if (dist[next.num] <= nextcost) continue;
			dist[next.num] = nextcost;
			pq.push({ next.num, nextcost });
		}
	}
}
void dijkstra2(int start) {
	for (int i = 0; i <= n; i++) {
		dist2[i] = 21e8;
	}
	priority_queue<node>pq;
	pq.push({ start, 0 });
	dist2[start] = 0;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();
		if (now.num == x) break;

		if (dist2[now.num] < now.cost) continue;
		for (int i = 0;i < arr[now.num].size(); i++) {
			node next = arr[now.num][i];
			int nextcost = dist2[now.num] + next.cost;

			if (dist2[next.num] <= nextcost) continue;
			dist2[next.num] = nextcost;
			pq.push({ next.num, nextcost });
		}
	}
}

int main() {
	
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to, cost });
	}


	dijkstra(x);
	for (int i = 1; i <= n; i++) {
		dijkstra2(i);
		if (dist[i] == 21e8 || dist2[x] == 21e8) continue;
		if (dist[i] + dist2[x] > Max) Max = dist[i] + dist2[x];
	}

	cout << Max;

	return 0;
}