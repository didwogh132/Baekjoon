#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int n, m;
int arr[501][501];
struct node {
    int y;
    int x;
    int cost;
    bool operator <(node right) const {
        if (cost > right.cost) return true;
        if (cost < right.cost) return false;
        return false;
    }
};
int dist[501][501];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };

void func(int y1, int x1, int y2, int x2) {
    if (y1 <= y2) {
        if (x1 <= x2) {
            for (int a = y1; a <= y2; a++) {
                for (int b = x1; b <= x2; b++) {
                    arr[a][b] = 1;
                }
            }
        }
        else {
            for (int a = y1; a <= y2; a++) {
                for (int b = x2; b <= x1; b++) {
                    arr[a][b] = 1;
                }
            }
        }
    }
    else {
        if (x1 <= x2) {
            for (int a = y2; a <= y1; a++) {
                for (int b = x1; b <= x2; b++) {
                    arr[a][b] = 1;
                }
            }
        }
        else {
            for (int a = y2; a <= y1; a++) {
                for (int b = x2; b <= x1; b++) {
                    arr[a][b] = 1;
                }
            }
        }
    }
}
void func2(int y1, int x1, int y2, int x2) {
    if (y1 <= y2) {
        if (x1 <= x2) {
            for (int a = y1; a <= y2; a++) {
                for (int b = x1; b <= x2; b++) {
                    arr[a][b] = 2;
                }
            }
        }
        else {
            for (int a = y1; a <= y2; a++) {
                for (int b = x2; b <= x1; b++) {
                    arr[a][b] = 2;
                }
            }
        }
    }
    else {
        if (x1 <= x2) {
            for (int a = y2; a <= y1; a++) {
                for (int b = x1; b <= x2; b++) {
                    arr[a][b] = 2;
                }
            }
        }
        else {
            for (int a = y2; a <= y1; a++) {
                for (int b = x2; b <= x1; b++) {
                    arr[a][b] = 2;
                }
            }
        }
    }
}

void dijkstra(int y, int x) {
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    priority_queue<node> pq;
    pq.push({ y, x, 0 });
    dist[y][x] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.y][now.x] < now.cost) continue;

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny > 500 || nx > 500) continue;
            if (arr[ny][nx] == 2) continue;
            int nextcost = dist[now.y][now.x] + arr[ny][nx];
            if (dist[ny][nx] <= nextcost) continue;
            dist[ny][nx] = nextcost;
            pq.push({ ny, nx, nextcost });
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        func(y1, x1, y2, x2);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        func2(y1, x1, y2, x2);
    }
    dijkstra(0, 0);

    if (dist[500][500] == INT_MAX) {
        cout << -1;
    }
    else {
        cout << dist[500][500];
    }
    return 0;
}