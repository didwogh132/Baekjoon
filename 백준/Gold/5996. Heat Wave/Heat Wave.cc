#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m, a, b;
struct node {
    int num;
    int cost;
    bool operator<(node right) const {
        return cost > right.cost;
    }
};
vector<node> arr[2505];
int dist[2505];

void dijkstra(int num) {
    fill(dist, dist + n + 1, INT_MAX);

    priority_queue<node> pq;
    pq.push({ num, 0 });
    dist[num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = dist[now.num] + next.cost;
            if (dist[next.num] <= nextcost) continue;
            dist[next.num] = nextcost;
            pq.push({ next.num, nextcost });
        }
    }
}

int main() {

    cin >> n >> m >> a >> b;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
    }

    dijkstra(a);

    cout << dist[b];
    return 0;
}