#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

int n, m, k;
int dist[101][10010];
struct node {
    int num;
    int cost;
    int d;
    bool operator<(const node& right) const {
        if (d != right.d) return d > right.d;
        return cost > right.cost;
    }
};
vector<node> arr[101];

void dijkstra(int num) {
    queue<node> pq;
    pq.push({ num, 0, 0 });
    dist[num][0] = 0;

    while (!pq.empty()) {
        node now = pq.front(); pq.pop();

        if (dist[now.num][now.cost] < now.d) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = now.cost + next.cost;
            int nextd = now.d + next.d;
            if (nextcost > m) continue;
            if (dist[next.num][nextcost] <= nextd) continue;
            dist[next.num][nextcost] = nextd;
            
            for (int c = nextcost + 1; c <= m; c++) {
                if (dist[next.num][c] <= nextd) break;
                dist[next.num][c] = nextd;
            }
            
            pq.push({ next.num, nextcost, nextd });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        cin >> n >> m >> k;

        for (int i = 1; i <= n; i++) {
            arr[i].clear();
        }

        for (int i = 0; i <= n; i++) {
            fill(dist[i], dist[i] + m + 1, INT_MAX);
        }

        for (int i = 0; i < k; i++) {
            int from, to, cost, d;
            cin >> from >> to >> cost >> d;
            arr[from].push_back({ to, cost, d });
        }

        dijkstra(1);

        int ans = INT_MAX;
        for (int i = 0; i <= m; i++) {
            if (dist[n][i] < ans) ans = dist[n][i];
        }

        if (ans == INT_MAX) {
            cout << "Poor KCM" << "\n";
        }
        else {
            cout << ans << "\n";
        }
    }
    return 0;
}