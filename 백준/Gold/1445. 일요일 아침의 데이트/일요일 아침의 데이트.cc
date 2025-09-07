#include <iostream>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int n, m;
string arr[51];
struct node {
    int y;
    int x;
};
struct node2 {
    int y;
    int x;
    int cost;
    bool operator <(node2 right) const {
        return cost > right.cost;
    }
};
int arr2[51][51];
int sy, sx, ey, ex;
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int dist[51][51];

void dijkstra(int y, int x) {

    for (int i = 0; i < n; i++) {
        fill(dist[i], dist[i] + m + 1, INT_MAX);
    }
    priority_queue<node2> pq;
    pq.push({ y, x, 0 });
    dist[y][x] = 0;

    while (!pq.empty()) {
        node2 now = pq.top(); pq.pop();

        if (dist[now.y][now.x] < now.cost) continue;

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            int nextcost = dist[now.y][now.x] + arr2[ny][nx];
            
            if (dist[ny][nx] <= nextcost) continue;
            dist[ny][nx] = nextcost;
            pq.push({ ny, nx, nextcost });
        }
    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    queue<node> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '.') continue;
            else if (arr[i][j] == 'S') {
                sy = i;
                sx = j;
            }
            else if (arr[i][j] == 'F') {
                ey = i;
                ex = j;
            }
            else {
                q.push({ i, j });
                arr2[i][j] = 10000;
            }
        }
    }
    while (!q.empty()) {
        node now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] == 'F' || arr[ny][nx] == 'S' || arr[ny][nx] == 'g') continue;
            arr2[ny][nx] = 1;
        }
    }

    dijkstra(sy, sx);
    

    cout << dist[ey][ex] / 10000 << " " << dist[ey][ex] % 10000;

    return 0;
}