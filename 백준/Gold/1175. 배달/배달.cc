#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int n, m;
int sy, sx;
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
string arr[52];
struct node {
    int y;
    int x;
    int dir;
    int mask;
};
struct nodes {
    int y;
    int x;
};
nodes End[2];
int end_cnt;
int visited[5][4][52][52];

int bfs(int y, int x, int dir, int mask) {
    queue<node> q;
    q.push({ y, x, dir, mask});
    visited[dir][mask][y][x] = 0;

    while (!q.empty()) {
        node now = q.front(); q.pop();

        if (now.mask == 3) {
            return visited[now.dir][now.mask][now.y][now.x];
        }

        for (int i = 0; i < 4; i++) {
            if (now.dir != 4 && now.dir == i) continue;
            else {
                int ny = now.y + ydir[i];
                int nx = now.x + xdir[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (arr[ny][nx] == '#') continue;
                int nmask = now.mask;

                if (ny == End[0].y && nx == End[0].x) nmask |= 1;
                if (ny == End[1].y && nx == End[1].x) nmask |= 2;

                if (visited[i][nmask][ny][nx] > -1) continue;
                visited[i][nmask][ny][nx] = visited[now.dir][now.mask][now.y][now.x] + 1;
                q.push({ ny, nx, i , nmask});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(visited, -1, sizeof(visited));

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'S') {
                sy = i;
                sx = j;
            }
            else if (arr[i][j] == 'C') {
                End[end_cnt] = { i, j };
                end_cnt++;
            }
        }
    }

    cout << bfs(sy, sx, 4, 0);

    return 0;
}
