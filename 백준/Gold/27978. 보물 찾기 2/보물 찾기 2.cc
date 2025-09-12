#include <iostream>
#include <cstring>
#include <string>
#include <climits>
#include <queue>

using namespace std;

int n, m;
string arr[501];
int sy, sx, ey, ex;
int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
struct node {
    int y;
    int x;
    int cost;
    bool operator< (node right) const {
        return cost > right.cost;
    }
};
int dist[501][501];

void dijkstra(int y, int x) {
    priority_queue<node> pq;
    pq.push({ y, x, 0 });
    dist[y][x] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.y][now.x] < now.cost) continue;

        for (int i = 0; i < 8; i++) {
            int ny;
            int nx;
            int nextcost;
            if (i < 5) {
                ny = now.y + ydir[i];
                nx = now.x + xdir[i];
                nextcost = dist[now.y][now.x] + 1;
            }
            else {
                ny = now.y + ydir[i];
                nx = now.x + xdir[i];
                nextcost = dist[now.y][now.x];
            }
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] == '#') continue;
            if (dist[ny][nx] <= nextcost) continue;
            dist[ny][nx] = nextcost;

            pq.push({ ny, nx, nextcost });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        fill(dist[i], dist[i] + m, INT_MAX);
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'K') {
                sy = i;
                sx = j;
            }
            else if (arr[i][j] == '*') {
                ey = i;
                ex = j;
            }
        }
    }

    dijkstra(sy, sx);

    int ans = (dist[ey][ex] == INT_MAX) ? -1 : dist[ey][ex];
    cout << ans;

    return 0;
}