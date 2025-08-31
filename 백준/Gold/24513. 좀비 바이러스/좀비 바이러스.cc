#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
int arr[1010][1010];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int visited[1010][1010];
int result[1010][1010];
struct node {
    int y;
    int x;
    int time;
    int type;
};
queue<node> q;
int cnt1, cnt2, cnt3;

void bfs() {
    while (!q.empty()) {
        node now = q.front(); q.pop();

        if (result[now.y][now.x] == 3) continue;

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] == -1 ) continue;
            if (visited[ny][nx] == -1) {
                visited[ny][nx] = now.time + 1;
                result[ny][nx] = now.type;
                q.push({ ny, nx, now.time + 1, now.type });
            }
            else if (visited[ny][nx] == now.time + 1 && result[ny][nx] != now.type && result[ny][nx] != 3) {
                result[ny][nx] = 3;
                continue;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(visited, -1, sizeof(visited));
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({ i, j, 0, 1 });
                visited[i][j] = 0;
                result[i][j] = 1;
            }
            else if (arr[i][j] == 2) {
                q.push({ i, j, 0, 2 });
                visited[i][j] = 0;
                result[i][j] = 2;
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (result[i][j] == 1) {
                cnt1++;
            }
            else if (result[i][j] == 2) {
                cnt2++;
            }
            else if (result[i][j] == 3) {
                cnt3++;
            }
        }
    }
    cout << cnt1 << " " << cnt2 << " " << cnt3;
    
    return 0;
}