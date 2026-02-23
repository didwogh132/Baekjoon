#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node {
    int y;
    int x;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int r1, c1, r2, c2;
    cin >> r1 >> c1;
    cin >> r2 >> c2;

    int sy = r1 - 1, sx = c1 - 1;
    int ty = r2 - 1, tx = c2 - 1;

    vector<vector<vector<char>>> visit(2, vector<vector<char>>(n, vector<char>(m, 0)));

    queue<Node> q;
    visit[0][sy][sx] = 1;
    q.push(Node{ sy, sx });

    int dy[4] = { -1, 1, 0, 0 };
    int dx[4] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visit[0][ny][nx]) continue;
            
            if (grid[ny][nx] == '.') {
                visit[0][ny][nx] = 1;
                q.push(Node{ ny, nx });
            }
            else {
                if (ny == ty && nx == tx && grid[ty][tx] == '.') {
                    visit[0][ny][nx] = 1;
                    q.push(Node{ ny, nx });
                }
            }
        }
    }

    int aroundDot = 0;
    for (int dir = 0; dir < 4; dir++) {
        int ny = ty + dy[dir];
        int nx = tx + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (grid[ny][nx] == '.') aroundDot++;
    }

    bool startAdjTarget = false;
    for (int dir = 0; dir < 4; dir++) {
        int ny = ty + dy[dir];
        int nx = tx + dx[dir];
        if (ny == sy && nx == sx) {
            startAdjTarget = true;
            break;
        }
    }

    bool canEscape = false;

    if (sy == ty && sx == tx) {
        if (aroundDot >= 1) canEscape = true;
    }
    else if (grid[ty][tx] == 'X') {
        for (int dir = 0; dir < 4; dir++) {
            int ny = ty + dy[dir];
            int nx = tx + dx[dir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visit[0][ny][nx]) {
                canEscape = true;
                break;
            }
        }
    }
    else {
        if (visit[0][ty][tx]) {
            if (startAdjTarget) {
                if (aroundDot >= 1) canEscape = true;
            }
            else {
                if (aroundDot >= 2) canEscape = true;
            }
        }
    }

    if (canEscape) visit[1][ty][tx] = 1;

    cout << (visit[1][ty][tx] ? "YES" : "NO");
    return 0;
}