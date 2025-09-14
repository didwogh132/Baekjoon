#include <iostream>
#include <cstring>
#include <string>
#include <climits>
#include <queue>

using namespace std;

int n, t;
int arr[105][105];
long long dist[105][105][3];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };

struct node {
    unsigned int num;
    long long cost;
    bool operator <(node right) const {
        return cost > right.cost;
    }
};

void dijkstra(int y, int x) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j][0] = INT_MAX;
            dist[i][j][1] = INT_MAX;
            dist[i][j][2] = INT_MAX;
        }
    }
    priority_queue<node> pq;
    unsigned int start = ((unsigned int)0 << 10) | ((unsigned int)0 << 2) | (unsigned int)0;
    dist[0][0][0] = 0;
    pq.push({ start, 0 });

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        int now_mod = now.num & 0x3;
        int now_x = (now.num >> 2) & 0x7f;
        int now_y = (now.num >> 10 )& 0x7f;

        if (dist[now_y][now_x][now_mod] < now.cost) continue;

        for (int i = 0; i < 4; i++) {
            int ny = now_y + ydir[i];
            int nx = now_x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

            int nextmod = (now_mod + 1) % 3;
            int nextcost = now.cost + t;
            if (nextmod == 0) nextcost += arr[ny][nx];

            if (nextcost < dist[ny][nx][nextmod]) {
                dist[ny][nx][nextmod] = nextcost;

                unsigned int next = ((unsigned int)ny << 10) | ((unsigned int)nx << 2) | ((unsigned int)nextmod);

                pq.push({ next, nextcost });
            }
        }
    }
}


int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    dijkstra(0, 0);

    int ans = (dist[n - 1][n - 1][0] < dist[n - 1][n - 1][1]) ? dist[n - 1][n - 1][0] : dist[n - 1][n - 1][1];
    ans = (ans < dist[n - 1][n - 1][2]) ? ans : dist[n - 1][n - 1][2];

    cout << ans;

    return 0;
}