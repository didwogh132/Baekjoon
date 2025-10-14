#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

int visited[150][10010];
int n, m;
bool arr[10010];
int dir[] = { -1, 0, 1 };
struct node {
	int num;
	int cost;
};

void bfs() {
	queue<node> q;
	q.push({ 1, 0 });
	visited[0][1] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		if (now.num == n) {
            cout << visited[now.cost][now.num];
            return;
        }
        else if (now.num > n) continue;

		for (int i = 0; i < 3; i++) {
			int nextcost = now.cost + dir[i];
			int next = now.num + nextcost;
			if (next <= 1) continue;
			if (nextcost < 0) continue;
			if (arr[next]) continue;
			if (visited[nextcost][next] > -1) continue;
			visited[nextcost][next] = visited[now.cost][now.num] + 1;
			q.push({ next, nextcost });
		}
	}
    cout << -1;
    return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(visited, -1, sizeof(visited));
	memset(arr, false, sizeof(arr));
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		arr[num] = true;
	}

	bfs();

	return 0;
}