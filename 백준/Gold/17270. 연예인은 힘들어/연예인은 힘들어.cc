#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct node {
    int num;
    int cost;
    bool operator<(const node& right) const {
        return cost > right.cost;
    }
};
vector<node> arr[101];
int dist[2][101];
int n, m;

void dijkstra(int num, bool flag) {
    priority_queue<node> pq;
    int x;
    if (flag) x = 1;
    else x = 0;
    dist[x][num] = 0;
    pq.push({ num, 0 });
    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[x][now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            int next = arr[now.num][i].num;
            int nextcost = now.cost + arr[now.num][i].cost;

            if (dist[x][next] > nextcost) {
                dist[x][next] = nextcost;
                pq.push({ next, nextcost });
            }

        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
    }

    int j, s;
    cin >> j >> s;

    for (int i = 0; i < 2; i++) {
        for (int k = 0; k <= n; k++) {
            dist[i][k] = INT_MAX;
        }
    }

    dijkstra(j, false);
    dijkstra(s, true);

    int minsum = INT_MAX;

    for (int i = 1; i <= n; i++) {
        if (i == j || i == s) continue;
        if (dist[0][i] == INT_MAX || dist[1][i] == INT_MAX) continue;

        int sum = dist[0][i] + dist[1][i];
        if (sum < minsum) minsum = sum;
    }

    int ans = -1;
    int best_j = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (i == j || i == s) continue;
        if (dist[0][i] == INT_MAX || dist[1][i] == INT_MAX) continue;

        int sum = dist[0][i] + dist[1][i];
        if (sum != minsum) continue;
        if (dist[0][i] > dist[1][i]) continue;

        if (dist[0][i] < best_j) {
            best_j = dist[0][i];
            ans = i;
        }
        else if (dist[0][i] == best_j) {
            if (ans == -1 || i < ans) ans = i;
        }
    }

    cout << ans;

    return 0;
}