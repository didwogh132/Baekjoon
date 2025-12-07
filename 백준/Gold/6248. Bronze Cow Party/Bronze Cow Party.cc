#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int n, m, x;
struct node {
    int num;
    int cost;
    bool operator <(const node& right) const {
        if (cost != right.cost) return cost > right.cost;
        return false;
    }
};
vector<node> arr[1010];
int dist[1010];

void dijkstra(int num) {
    memset(dist, 0x7f, sizeof(dist));
    priority_queue<node> pq;
    pq.push({ num, 0 });
    dist[num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = now.cost + next.cost;

            if (dist[next.num] <= nextcost) continue;
            dist[next.num] = nextcost;
            pq.push({ next.num, nextcost });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
    }

    dijkstra(x);

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        ans = (ans > dist[i]) ? ans : dist[i];
    }
    cout << ans * 2;

    return 0;
}