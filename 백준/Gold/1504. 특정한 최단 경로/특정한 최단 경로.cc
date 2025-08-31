#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

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
vector<node> arr[801];
int dist[801];
int n, e;
int Min1 = 2e8;
int Min2 = 2e8;
int v1, v2;

void dijkstra1(int start) {
	for (int i = 0; i <= n; i++) {
		dist[i] = 2e8;
	}
	priority_queue<node>pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();
		if (now.num == v1) break;
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
void dijkstra2(int start) {
	for (int i = 0; i <= n; i++) {
		dist[i] = 2e8;
	}
	priority_queue<node>pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();
		if (now.num == v2) break;
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
void dijkstra3(int start) {
	for (int i = 0; i <= n; i++) {
		dist[i] = 2e8;
	}
	priority_queue<node>pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();
		if (now.num == n) break;
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
	
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to,cost });
		arr[to].push_back({ from,cost });
	}
	
	cin >> v1 >> v2;
	
	dijkstra1(1);
	Min1 = dist[v1];
	dijkstra2(v1);
	Min1 += dist[v2];
	dijkstra3(v2);
	Min1 += dist[n];
	dijkstra2(1);
	Min2 = dist[v2];
	dijkstra1(v2);
	Min2 += dist[v1];
	dijkstra3(v1);
	Min2 += dist[n];
	if (dist[v1] < dist[v2]) {

	}
	else {
		

	}
	if (Min1 >= 2e8 && Min2 >= 2e8) {
		cout << -1;
	}
	else if (Min1 < Min2) {
		cout << Min1;
	}
	else {
		cout << Min2;
	}


	return 0;
}