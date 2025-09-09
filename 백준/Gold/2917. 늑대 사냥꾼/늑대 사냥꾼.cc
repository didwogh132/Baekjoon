#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int n, m;
string arr[505];
struct node {
    int y;
    int x;
    int cost;
    int Min;
    bool operator <(node right) const {
        return cost < right.cost;
    }
};
struct node2 {
    int y;
    int x;
};
int sy, sx, ey, ex;
queue<node2> q;
priority_queue<node> pq;
int visited[505][505];
int dist[505][505];
int ydir[] = { 0, 0, -1, 1 };
int xdir[] = { 1, -1, 0, 0 };

void bfs() {

    while (!q.empty()) {
        node2 now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx] > -1) continue;
            visited[ny][nx] = visited[now.y][now.x] + 1;
            q.push({ ny, nx });
        }
    }
}
void dijkstra(int y, int x) {
    pq.push({ y, x, visited[y][x]});
    dist[y][x] = visited[y][x];

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.y][now.x] > now.cost) continue;
        if (now.y == ey && now.x == ex) break;
        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            int nextcost = (visited[ny][nx] > now.cost) ? now.cost : visited[ny][nx];
            if (dist[ny][nx] >= nextcost) continue;
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
    }
    memset(visited, -1, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '+') {
                q.push({ i, j });
                visited[i][j] = 0;
            }
            else if (arr[i][j] == 'V') {
                sy = i;
                sx = j;
            }
            else if(arr[i][j] == 'J'){
                ey = i;
                ex = j;
            }
        }
    }
    bfs();

    dijkstra(sy, sx);

    cout << dist[ey][ex];


    return 0;
}