#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int n, m, k;
int arr[105][105];
int visited[105][105];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
struct node {
    int y;
    int x;
};
int Max;

void bfs(int y, int x) {
    queue<node> q;
    q.push({ y, x });
    visited[y][x] = 1;
    int cnt = 1;

    while (!q.empty()) {
        node now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] == 0) continue;
            if (visited[ny][nx] > -1) continue;
            visited[ny][nx] = visited[now.y][now.x] + 1;
            cnt++;
            q.push({ ny, nx });
        }
    }
    if (cnt > Max) Max = cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(visited, -1, sizeof(visited));
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        arr[y - 1][x - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && visited[i][j] == -1) {
                bfs(i, j);
            }
        }
    }

    cout << Max;

    return 0;
}