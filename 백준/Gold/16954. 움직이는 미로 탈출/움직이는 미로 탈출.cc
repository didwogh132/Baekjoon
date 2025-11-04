#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

struct Node { 
    int y; 
    int x; 
};
char arr[8][8];
int dy[9] = { -1,-1,-1, 0,0,0, 1,1,1 };
int dx[9] = { -1, 0, 1,-1,0,1,-1,0,1 };

void moveWalls() {
    for (int y = 7; y >= 1; y--) {
        for (int x = 0; x < 8; x++) {
            arr[y][x] = arr[y - 1][x];
        }
    }
    for (int x = 0; x < 8; x++) arr[0][x] = '.';
}

bool solve() {
    queue<Node> q;
    q.push({ 7,0 });

    while (!q.empty()) {
        bool visited[8][8];
        memset(visited, false, sizeof(visited));

        int sz = q.size();

        for (int s = 0; s < sz; s++) {
            Node now = q.front(); q.pop();

            if (arr[now.y][now.x] == '#') continue;

            if (now.y == 0 && now.x == 7) return true;

            for (int dir = 0; dir < 9; dir++) {
                int ny = now.y + dy[dir];
                int nx = now.x + dx[dir];

                if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8) continue;
                if (arr[ny][nx] == '#') continue;
                if (visited[ny][nx]) continue;

                visited[ny][nx] = true;
                q.push({ ny, nx });
            }
        }
        moveWalls();
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> arr[i][j];
        }
    }

    cout << (solve() ? 1 : 0);
    return 0;
}