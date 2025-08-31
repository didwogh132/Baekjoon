#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

int n, m;
long long dist[100010];
int check[100010];
struct node {
	int num;
	long long cost;
	bool operator<(node right) const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;
		return false;
	}
};
vector<node> arr[100010];

void dijkstra(int start) {
	for (int i = 0; i < n; i++) {
		dist[i] = LLONG_MAX;
	}
	priority_queue<node> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dist[now.num] < now.cost) continue;

		for (int i = 0; i < arr[now.num].size(); i++) {
			node next = arr[now.num][i];
			long long nextcost = dist[now.num] + next.cost;

			if (next.num < n-1 && check[next.num] == 1) continue;
			if (dist[next.num] <= nextcost) continue;
			dist[next.num] = nextcost;
			pq.push({ next.num, nextcost });
		}
	}
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> check[i];
	}
	for (int i = 0; i < m; i++) {
		int from, to;
		long long cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to, cost });
		arr[to].push_back({ from, cost });
	}

	dijkstra(0);

	if (dist[n - 1] == LLONG_MAX) {
		cout << -1;
	}
	else {
		cout << dist[n - 1];
	}

	return 0;
}