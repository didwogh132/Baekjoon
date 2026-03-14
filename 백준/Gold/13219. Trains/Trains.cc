#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct node {
    int y, x;
    long long cost;
    bool operator<(const node& right) const {
        return cost > right.cost;
    }
};

int arr[402][402];
long long dist[402][402];
int ydir[] = {-1, 1, 0, 0};
int xdir[] = {0, 0, -1, 1};
int sy, sx, ey, ex;
int n;

void dijkstra(int sy, int sx) {
    for(int i =1; i <= n; i++) {
        for(int j =1; j <= n; j++) {
            dist[i][j] = LLONG_MAX;
        }
    }

    priority_queue<node> pq;
    pq.push({sy, sx, arr[sy][sx]});
    dist[sy][sx] = arr[sy][sx];

    while(!pq.empty()) {
        node now = pq.top(); pq.pop();

        if(dist[now.y][now.x] < now.cost) continue;

        for(int i=0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if(ny < 1 || nx < 1 || ny > n || nx > n) continue;
            if(arr[ny][nx] == -1) continue;
            long long cost = now.cost + arr[ny][nx];
            if(dist[ny][nx] <= cost) continue;
            dist[ny][nx] = cost;
            pq.push({ny, nx, cost});
        }
    }
}

int main() {
    cin >> n;

    cin >> sx >> sy >> ex >> ey;

    for(int i =1; i <=n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    
    if (arr[sy][sx] == -1 || arr[ey][ex] == -1) {
        cout << -1;
        return 0;
    }
    
    dijkstra(sy, sx);

    if(dist[ey][ex] == LLONG_MAX) cout << -1;
    else cout << dist[ey][ex];
    return 0;
}