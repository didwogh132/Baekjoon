#include <iostream>
#include <climits>
#include <queue>

using namespace std;

struct node {
	int value;
	int count;
};

int main() {
	int n;
	cin >> n;
	queue<node> q;
	int visited[50001] = {};
	q.push({ 0, 0 });
	visited[0] = 1;

	while (!q.empty()) {
		node now = q.front(); q.pop();
		if (now.value == n) {
			cout << now.count;
			return 0;
		}

		for (int i = 1; i * i <= n; i++) {
			int next = now.value + i * i;
			if (next <= n && visited[next] == 0) {
				visited[next] = 1;
				q.push({ next, now.count + 1 });
			}
		}
	}

}