#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
vector<int> alis[101];
int visited[101];
int cnt;
int max1;

void dfs(int start) {
	if (cnt > max1) {
		max1 = cnt;
	}

	for (int i = 0; i < alis[start].size(); i++) {
		int next = alis[start][i];
		if (visited[next] == 1) continue;
		visited[next] = 1;
		cnt++;
		dfs(next);
	}

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;

		alis[from].push_back(to);
		alis[to].push_back(from);
	}

	for (int i = 1; i <= N; i++) {
		cnt = 0;
		visited[i] = 1;
		dfs(i);
		visited[i] = 0;
		if (cnt > max1) max1 = cnt;

	}
	cout << max1;
	

	return 0;
}