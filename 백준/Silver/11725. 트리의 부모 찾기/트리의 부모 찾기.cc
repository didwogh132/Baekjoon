#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

vector<int> arr[100010];
int visited[100010];

void bfs(int num) {
    queue<int> q;
    q.push(num);
    visited[num] = 0;

    while (!q.empty()) {
        int now = q.front(); q.pop();

        for (int i = 0; i < arr[now].size(); i++) {
            int next = arr[now][i];
            if (visited[next] > -1) continue;
            visited[next] = now;
            q.push(next);
        }
    }
}

int main() {
    memset(visited, -1, sizeof(visited));
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int from, to;
        cin >> from >> to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }
    bfs(1);

    for (int i = 2; i <= n; i++) {
        cout << visited[i] << "\n";
    }
    return 0;
}