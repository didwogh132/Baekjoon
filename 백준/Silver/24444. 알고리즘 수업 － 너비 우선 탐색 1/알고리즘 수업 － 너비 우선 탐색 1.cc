#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m, r;
vector<int>arr[100010];
int visited[100010];
int cnt = 1;

void bfs(int start) {
	queue<int>q;
	q.push(start);
	visited[start] = cnt;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			if (visited[next] > 0) continue;
			cnt++;
			visited[next] = cnt;

			q.push(next);
		}
	}
}


int main() {

	
	cin >> n >> m >> r;

	for (int i = 0;i < m; i++) {
		int from, to;
		cin >> from >> to;
		arr[from].push_back(to);
		arr[to].push_back(from);
	}
	for (int i = 0; i <= n; i++) {
		sort(arr[i].begin(), arr[i].end());
	}

	bfs(r);

	for (int i = 1; i <= n; i++) {
		cout << visited[i] << "\n";
	}

	return 0;
}