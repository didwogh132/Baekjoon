#include <iostream>
#include <queue>

using namespace std;

int n, m, k;
string arrs[1010];
int arr[1010][1010];
int visited[2][11][1010][1010];
struct node {
    int y;
    int x;
    int k;
    int visit;
    int day;
};
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int Time = 0;

void bfs(int y, int x) {
    queue<node> q;
    q.push({ y, x, 0, 1, 0 });
    visited[0][0][y][x] = 1;

    while (!q.empty()) {
        node now = q.front(); q.pop();

        if (now.y == n - 1 && now.x == m - 1) {
            cout << now.visit;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            if (arr[ny][nx] == 0 && visited[1 - now.day][now.k][ny][nx] == 0) {
                visited[1 - now.day][now.k][ny][nx] = 1;
                q.push({ ny, nx, now.k, now.visit + 1, 1 - now.day });
            }

            else if (arr[ny][nx] == 1 &&  now.k < k) {
                if (now.day == 0 && visited[1 - now.day][now.k + 1][ny][nx] == 0) {
                    visited[1 - now.day][now.k + 1][ny][nx] = 1;
                    q.push({ ny, nx, now.k + 1, now.visit + 1, 1 - now.day });
                }
            }
        }
        if (visited[1 - now.day][now.k][now.y][now.x] == 0) {
            visited[1 - now.day][now.k][now.y][now.x] = 1;
            q.push({ now.y, now.x, now.k, now.visit + 1, 1 - now.day });
        }
    }
    cout << -1;
}

int main() {

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> arrs[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arrs[i][j] == '0') {
                arr[i][j] = 0;
            }
            else {
                arr[i][j] = 1;
            }
        }
    }

    bfs(0, 0);
    return 0;
}