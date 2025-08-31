#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

struct node {
    int y;
    int x;
};
int n, m;
string arr[601];
int visited[601][601];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int cnt = 0;

void bfs(int y, int x) {
    queue<node> q;
    q.push({ y, x });
    visited[y][x] = 0;

    while (!q.empty()) {
        node now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] == 'X') continue;
            if (visited[ny][nx] > -1) continue;
            if (arr[ny][nx] == 'P') cnt++;
            visited[ny][nx] = visited[now.y][now.x] + 1;
            q.push({ ny, nx });
        }
    }
}
int main() {
    memset(visited, -1, sizeof(visited));

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'I') {
                bfs(i, j);
                break;
            }
        }
    }
    if (cnt == 0) {
        cout << "TT";
    }
    else {
        cout << cnt;
    }
    return 0;
}