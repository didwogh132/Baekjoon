#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

string arr[1010];
int visited[11][1010][1010];
struct node {
    int y;
    int x;
    int k;
};
int n, m, k;
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };

void bfs(int y, int x, int k) {
    queue<node> q;
    q.push({ y, x, k });
    visited[k][y][x] = 0;

    while (!q.empty()) {
        node now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            int nk = now.k;
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            
            if (arr[ny][nx] == '1' && nk > 0) {
                if (visited[nk - 1][ny][nx] == -1) {
                    visited[nk - 1][ny][nx] = visited[now.k][now.y][now.x] + 1;
                    q.push({ ny, nx, nk - 1 });
                }
            }
            else if (arr[ny][nx] == '0') {
                if (visited[nk][ny][nx] == -1) {
                    visited[nk][ny][nx] = visited[now.k][now.y][now.x] + 1;
                    q.push({ ny, nx, nk });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(visited, -1, sizeof(visited));
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bfs(0, 0, k);

    int Min = INT_MAX;
    for (int i = 0; i <= k; i++) {
        if (visited[i][n - 1][m - 1] != -1) {
            if (visited[i][n - 1][m - 1] < Min) {
                Min = visited[i][n - 1][m - 1];
            }
        }
    }
    if (Min == INT_MAX) {
        cout << -1;
    }
    else {
        cout << Min + 1;
    }
    return 0;
}