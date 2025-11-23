#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

int n, m, k;
struct node {
    int num;
    long long cost;
    int use;
    bool operator<(const node& right) const {
        return cost > right.cost;
    }
};
struct edge {
    int num;
    long long cost;
};
vector<edge> arr[10010];
long long dist[21][10010];

void dijkstra(int num, int use) {
    for (int i = 0; i <= k; i++) {
        fill(dist[i], dist[i] + n + 1, LLONG_MAX);
    }
    priority_queue<node> pq;
    pq.push({ num, 0, use });
    dist[use][num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.use][now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            edge next = arr[now.num][i];
            long long nextcost = dist[now.use][now.num] + next.cost;
            int nextuse = now.use;
            
            if (dist[nextuse][next.num] <= nextcost) continue;
            dist[nextuse][next.num] = nextcost;
            pq.push({ next.num, nextcost, nextuse });

            if (now.use < k) {
                nextcost = dist[now.use][now.num];
                nextuse = now.use + 1;
                if (dist[nextuse][next.num] <= nextcost) continue;
                dist[nextuse][next.num] = nextcost;
                pq.push({ next.num, nextcost, nextuse });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int from, to;
        long long cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
    }

    dijkstra(1, 0);

    long long ans = LLONG_MAX;

    for (int i = 0; i <= k; i++) {
        ans = (dist[i][n] < ans) ? dist[i][n] : ans;
    }

    cout << ans;

    return 0;
}