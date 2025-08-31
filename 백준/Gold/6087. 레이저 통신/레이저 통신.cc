#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct node {
    int y;
    int x;
    int stat;
    int cost;
    bool operator <(node right) const {
        if (cost > right.cost) return true;
        if (cost < right.cost) return false;
        return false;
    }
};
int n, m;
string arr[101];
int dist[5][101][101];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
vector<node> a;

void dijkstra(int y, int x) {
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dist[k][i][j] = INT_MAX;
            }
        }
    }
    priority_queue<node> pq;
    pq.push({ y, x, 0, 0 });
    for (int i = 0; i < 4; i++) {
        dist[i][y][x] = 0;
    }

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.stat][now.y][now.x] < now.cost) continue;

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] == '*') continue;
            int nextcost = dist[now.stat][now.y][now.x];
            int nextstat;
            if (now.y == y && now.x == x) {
                nextstat = i;
            }
            else {
                if (now.stat == i) {
                    nextstat = now.stat;
                }
                else {
                    nextcost += 1;
                    nextstat = i;
                }

            }
            if (dist[nextstat][ny][nx] <= nextcost) continue;
            dist[nextstat][ny][nx] = nextcost;
            pq.push({ ny, nx, nextstat, nextcost });
        }
    }
}

int main() {
    
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'C') {
                a.push_back({ i, j });
            }
        }
    }
    dijkstra(a[0].y, a[0].x);
    int Min = INT_MAX;
    for (int i = 0; i < 4; i++) {
        if (dist[i][a[1].y][a[1].x] < Min) Min = dist[i][a[1].y][a[1].x];
    }
    cout << Min;

    return 0;
}