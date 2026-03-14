#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct node {
    int y, x;
    int cost;
    bool operator<(const node& other) const {
        return cost > other.cost;
    }
};
int arr[1001][1001];
int dist[1001][1001];
int ydir[] = {-1, 1, 0, 0};
int xdir[] = {0, 0, -1, 1};
int n;

void dijkstra(int y, int x) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    priority_queue<node> pq;
    pq.push({y, x, 0});
    dist[y][x] = 0;

    while(!pq.empty()) {
        node now = pq.top(); pq.pop();

        if(dist[now.y][now.x] < now.cost) continue;

        for(int i =0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            int cost = abs(arr[now.y][now.x] - arr[ny][nx]);
            int nxt_cost = (now.cost > cost) ? now.cost : cost;
            if(dist[ny][nx] <= nxt_cost) continue;
            dist[ny][nx] = nxt_cost;
            pq.push({ny, nx, nxt_cost});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    for(int i =0; i < n; i++) {
        for(int j =0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    dijkstra(0, 0);

    cout << dist[n-1][n-1];
    return 0;
}