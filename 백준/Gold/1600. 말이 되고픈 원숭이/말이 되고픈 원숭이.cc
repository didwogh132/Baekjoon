#include <iostream>
#include <cstring>
#include <climits>
#include <queue>

using namespace std;

int arr[205][205];
int visited[32][205][205];
int k;
int n, m;
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int yd[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int xd[] = {-2, -1, 1, 2, 2, 1, -1, -2};
struct node {
    int y;
    int x;
    int k;
};

void bfs(int y, int x, int k) {

    queue<node> q;
    q.push({ y, x, k });
    visited[k][y][x] = 0;

    while (!q.empty()) {
        node now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny, nx, nk;
            ny = now.y + ydir[i];
            nx = now.x + xdir[i];
            nk = now.k;

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] == 1)continue;
            if (visited[nk][ny][nx] > -1) continue;

            visited[nk][ny][nx] = visited[now.k][now.y][now.x] + 1;
            q.push({ ny, nx, nk });
        }
        if (now.k > 0) {
            for (int j = 0; j < 8; j++) {
                int ny, nx, nk;
                ny = now.y + yd[j];
                nx = now.x + xd[j];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (arr[ny][nx] == 1)continue;
                nk = now.k - 1;
                if (visited[nk][ny][nx] > -1) continue;
                visited[nk][ny][nx] = visited[now.k][now.y][now.x] + 1;
                q.push({ ny, nx, nk });
            }
        }
    }
}

int main() {
    memset(visited, -1, sizeof(visited));

    cin >> k;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    bfs(0, 0, k);

    int ans = INT_MAX;
    for (int i = 0; i <= k; i++) {
        if (visited[i][n - 1][m - 1] != -1) {
            if (visited[i][n - 1][m - 1] < ans) {
                ans = visited[i][n - 1][m - 1];
            }
        }
    }

    if (ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}
