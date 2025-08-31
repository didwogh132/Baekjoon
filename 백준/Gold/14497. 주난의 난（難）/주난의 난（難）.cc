#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct node {
    int y;
    int x;
    int cost;
    bool operator<(node right) const {
        if (cost > right.cost) return true;
        if (cost < right.cost) return false;
        return false;
    }
};
int n, m;
string arr[301];
node End;
node Start;
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int visited[301][301];

void dijkstra(node a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = INT_MAX;
        }
    }
    priority_queue<node> pq;
    pq.push({ a.y, a.x, 0 });
    visited[a.y][a.x] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (visited[now.y][now.x] < now.cost) continue;

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            int nextcost = visited[now.y][now.x] + (arr[ny][nx] - '0');
            if (visited[ny][nx] <= nextcost) continue;
            visited[ny][nx] = nextcost;
            pq.push({ ny, nx, nextcost });
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> Start.y >> Start.x >> End.y >> End.x;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Start.y -= 1;
    Start.x -= 1;
    Start.cost = 0;
    End.y -= 1;
    End.x -= 1;
    arr[Start.y][Start.x] = '0';
    arr[End.y][End.x] = '1';

    dijkstra(Start);

    cout << visited[End.y][End.x];
    
    return 0;
}