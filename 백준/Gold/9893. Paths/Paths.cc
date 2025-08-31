#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>

#define Max 1000010

using namespace std;

int n, m;
struct node {
    int num;
    int cost;
    int edge;
    bool operator<(node right) const {
        return cost > right.cost;
    }
};
vector<node> arr[101];
vector<int>  arr2[101];
int visited[101];
int dist[101];

void bfs(int num) {
    queue<int> q;
    q.push(num);
    visited[num] = 0;

    while (!q.empty()) {
        int now = q.front(); q.pop();

        for (int i = 0; i < arr2[now].size(); i++) {
            int next = arr2[now][i];
            if (visited[next] > -1) continue;
            visited[next] = visited[now] + 1;
            q.push(next);
        }
    }
}

void dijkstra(int num, int nodes) {

    fill(dist, dist + n + 1, INT_MAX);
    priority_queue<node> pq;
    pq.push({ num, 0, 0 });
    dist[num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = dist[now.num] + next.cost;
            int nextedge = now.edge + 1;
            if (dist[next.num] <= nextcost) continue;
            if (nextedge > visited[next.num]) continue;
            dist[next.num] = nextcost;
            pq.push({ next.num, nextcost, nextedge });
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(visited, -1, sizeof(visited));
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr2[from].push_back(to);
    }
    bfs(0);
    dijkstra(0, 0);


    cout << dist[1];

    return 0;
}