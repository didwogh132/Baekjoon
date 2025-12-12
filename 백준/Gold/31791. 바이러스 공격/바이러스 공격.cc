#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

char arr[1010][1010];
int n ,m, tg, tb, x, b;
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
struct node {
    int y;
    int x;
    int cost;
    bool operator <(const node& right) const {
        return cost > right.cost;
    }
};
int dist[1010][1010];
priority_queue<node> pq;

void dijkstra() {
    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.y][now.x] < now.cost) continue;

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            int nextcost = now.cost;
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] == '.') nextcost = now.cost + 1;
            else if (arr[ny][nx] == '#') nextcost = now.cost + tb + 1;

            if (dist[ny][nx] <= nextcost) continue;
            dist[ny][nx] = nextcost;
            pq.push({ ny, nx, nextcost });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dist, 0x7f, sizeof(dist));
    cin >> n >> m;
    cin >> tg >> tb >> x >> b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '*') {
                pq.push({ i, j, 0 });
                dist[i][j] = 0;
            }
        }
    }

    dijkstra();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] > tg) {
                cout << i + 1 << " " << j + 1 << "\n";
                ans++;
            }
        }
    }
    if (ans == 0) cout << -1;

    return 0;
}