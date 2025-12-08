#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

char arr[105][105];
struct node {
    int y;
    int x;
    int cost;
    bool operator <(const node& right) const {
        return cost > right.cost;
    }
};
int h, w;
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int dist[3][105][105];

void dijkstra(int idx, int y, int x) {
    priority_queue<node> pq;
    pq.push({ y, x, 0 });
    dist[idx][y][x] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[idx][now.y][now.x] < now.cost) continue;

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            int nextcost = now.cost;
            if (ny < 0 || nx < 0 || ny >= h + 2 || nx >= w + 2) continue;
            if (arr[ny][nx] == '*') continue;
            if (arr[ny][nx] == '#') {
                nextcost = now.cost + 1;
            }
            if (dist[idx][ny][nx] <= nextcost) continue;
            dist[idx][ny][nx] = nextcost;
            pq.push({ ny,nx, nextcost });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {

        cin >> h >> w;
        for (int i = 0; i < h + 2; i++) {
            for (int j = 0; j < w + 2; j++) {
                arr[i][j] = '.';
            }
        }
        int cnt = 0;
        int py[2];
        int px[2];
        memset(dist, 0x7f, sizeof(dist));
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == '$') {
                    py[cnt] = i;
                    px[cnt] = j;
                    arr[i][j] = '.';
                    cnt++;
                }
            }
        }
        dijkstra(0, 0, 0);
        dijkstra(1, py[0], px[0]);
        dijkstra(2, py[1], px[1]);

        int ans = 0x7f7f7f7f;

        for (int i = 0; i < h + 2; i++) {
            for (int j = 0; j < w + 2; j++) {
                if (arr[i][j] == '*') continue;

                if (dist[0][i][j] == 0x7f7f7f7f) continue;
                if (dist[1][i][j] == 0x7f7f7f7f) continue;
                if (dist[2][i][j] == 0x7f7f7f7f) continue;

                int sum = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];

                if (arr[i][j] == '#') {
                    sum -= 2;
                }
                ans = (ans > sum) ? sum : ans;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}