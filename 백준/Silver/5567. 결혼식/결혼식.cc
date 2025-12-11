#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

vector<int> arr[505];
int visited[505];

void bfs(int num) {
    queue<int> q;
    q.push(num);
    visited[num] = 0;

    while (!q.empty()) {
        int now = q.front(); q.pop();

        for (int i = 0; i < arr[now].size(); i++) {
            int next = arr[now][i];
            int nextcost = visited[now] + 1;
            if (visited[next] > -1) continue;
            visited[next] = nextcost;
            q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    memset(visited, -1, sizeof(visited));

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }
    bfs(1);

    int ans = 0;

    for (int i = 2; i <= n; i++) {
        if (visited[i] <= 2 && visited[i] != -1) ans++;
    }

    cout << ans;

    return 0;
}