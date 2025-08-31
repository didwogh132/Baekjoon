#include<iostream>
#include<vector>
#include<queue>
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
int n, m;
vector<node> arr[1010];
int dist[1010];
int visited[1010];
int visited2[1010];
int visited3[1010];
int path = 1;
int Max;
int now_dist;
int Now;
int Next;

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
			if (visited2[now.num] == Next && visited3[next.num] == Now) continue;
			visited[next.num] = now.num;
			dist[next.num] = nextcost;
			pq.push({ next.num, nextcost });
		}
	}
}


int main() {

	
	cin >> n >> m;
	memset(visited, -1, sizeof(visited));
	memset(visited2, -1, sizeof(visited2));
	memset(visited3, -1, sizeof(visited3));
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to, cost });
		arr[to].push_back({ from, cost });
	}

	dijkstra(1);
	now_dist = dist[n];

	int cur = n;
	while (cur != -1) {
		visited2[visited[cur]] = cur;
		visited3[cur] = visited[cur];
		cur = visited[cur];
	}
	for (int i = 1; visited2[i] <= n; i++) {
		if (visited2[i] == -1 || visited3[visited2[i]] == -1) continue;
		Now = visited3[visited2[i]];
		Next = visited2[i];
		dijkstra(1);
		int temp = dist[n] - now_dist;
		if (dist[n] == 21e8) {
			Max = -1;
			break;
		}
		if (temp > Max) {
			Max = temp;
		}
	}

	cout << Max;

	return 0;
}