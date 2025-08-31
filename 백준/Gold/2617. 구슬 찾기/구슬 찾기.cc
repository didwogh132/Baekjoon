#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<int> arr[100];
vector<int> arr2[100];
int visited[100][100];
int visited2[100][100];
int cnt;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start][start] = 0;

    while (!q.empty()) {
        int now = q.front(); q.pop();

        for (int i = 0; i < arr[now].size(); i++) {
            int next = arr[now][i];
            if (visited[start][next] > -1) continue;
            visited[start][next] = 1;
            q.push(next);
        }
    }
}
void bfs2(int start) {
    queue<int> q;
    q.push(start);
    visited2[start][start] = 0;

    while (!q.empty()) {
        int now = q.front(); q.pop();

        for (int i = 0; i < arr2[now].size(); i++) {
            int next = arr2[now][i];
            if (visited2[start][next] > -1) continue;
            visited2[start][next] = 1;
            q.push(next);
        }
    }
}

int main() {
    memset(visited, -1, sizeof(visited));
    memset(visited2, -1, sizeof(visited2));
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        arr[to].push_back(from);
        arr2[from].push_back(to);
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
        bfs2(i);
        int num = 0;
        int num2 = 0;
        for (int j = 1; j <= n; j++) {
            if (visited[i][j] == 1) {
                num++;
            }
            if (visited2[i][j] == 1) {
                num2++;
            }
        }
        if (num > (n / 2) || num2 > (n / 2)) cnt++;
    }

    cout << cnt;

    return 0;
}