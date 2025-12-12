#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int n, k;
int arr[205][205];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
struct node {
    int y;
    int x;
};
vector<node> p[1005];
int visited[205][205];
int s, x, y;
queue<node> q;
int t;
void bfs() {
    while (!q.empty()) {
        int a = q.size();
        t++;
        while (a--) {
            node now = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = now.y + ydir[i];
                int nx = now.x + xdir[i];
                int nextcost = visited[now.y][now.x];
                if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
                if (visited[ny][nx] > -1) continue;
                visited[ny][nx] = nextcost;
                q.push({ ny, nx });
            }
        }
        if (t == s) {
            if (visited[y][x] == -1) {
                cout << 0;
                return;
            }
            else {
                cout << visited[y][x];
                return;
            }
        }
    }

    if (visited[y][x] == -1) cout << 0;
    else cout << visited[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(visited, -1, sizeof(visited));
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0) {
                p[arr[i][j]].push_back({ i, j });
                visited[i][j] = arr[i][j];
            }
        }
    }
    cin >> s >> y >> x;

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < p[i].size(); j++) {
            q.push(p[i][j]);
        }
    }

    if (s > 0) {
        bfs();
    }
    else if (s == 0) {
        cout << arr[y][x];
    }

    return 0;
}