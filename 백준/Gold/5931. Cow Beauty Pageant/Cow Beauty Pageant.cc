#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<char>> arr;
vector<vector<int>> visited;
struct node {
    int y, x;
};
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int Min = 3000;

void bfs(int y, int x, bool flag) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '.') visited[i][j] = -1;
        }
    }
    queue<node> q;
    q.push({ y, x });
    visited[y][x] = 0;

    while (!q.empty()) {
        node now = q.front(); q.pop();


        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (flag) {
                if (arr[ny][nx] == '.') continue;
                if (visited[ny][nx] > -1) continue;
                visited[ny][nx] = visited[now.y][now.x] + 1;
                q.push({ ny, nx });
            }
            else {
                if (arr[ny][nx] == 'X' && visited[ny][nx] != -1) continue;
                if (arr[ny][nx] == 'X' && visited[ny][nx] == -1) {
                    Min = (Min < visited[now.y][now.x]) ? Min : (visited[now.y][now.x]);
                    return;
                }
                if (visited[ny][nx] > -1) continue;
                visited[ny][nx] = visited[now.y][now.x] + 1;
                q.push({ ny, nx });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    arr.resize(n, vector<char>(m, '.'));
    visited.resize(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    bool flag1 = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!flag1) {
                if (arr[i][j] == 'X') {
                    bfs(i, j, true);
                    flag1 = true;
                }
            }
            if(flag1) break;
        }
        if (flag1) break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'X' && visited[i][j] != -1) {
                bfs(i, j, false);
            }
        }
    }

    cout << Min;

    return 0;
}