#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int n, m, k;
int s, e;
struct edge {
    int num;
    int cost;
};
vector<edge> arr[1010];
struct node {
    int num;
    long long cost;
    int edge_cnt;
    bool operator <(node right) const {
        return cost > right.cost;
    }
};
long long dist[1010][1010];

void dijkstra(int num) {
    for (int i = 1; i <= n; i++) {
        fill(dist[i], dist[i] + n, LLONG_MAX);
    }
    priority_queue<node> pq;
    pq.push({ num, 0, 0 });
    dist[num][0] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.num][now.edge_cnt] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            int nextnum = arr[now.num][i].num;
            long long nextcost = dist[now.num][now.edge_cnt] + arr[now.num][i].cost;
            int nextedge = now.edge_cnt + 1;

            if (nextedge >= n) continue;
            if (dist[nextnum][nextedge] <= nextcost) continue;
            dist[nextnum][nextedge] = nextcost;
            pq.push({ nextnum, nextcost, nextedge });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    cin >> s >> e;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
    }

    dijkstra(s);

    long long min = LLONG_MAX;
    for (int j = 1; j < n; j++) {
        if (dist[e][j] == LLONG_MAX || dist[e][j] > min) continue;
        min = (min < (dist[e][j])) ? min : dist[e][j];
    }
    cout << min << "\n";

    long long tax = 0;

    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        tax += a;
        min = LLONG_MAX;
        for (int j = 1; j < n; j++) {
            if (dist[e][j] == LLONG_MAX) continue;
            min = (min < (dist[e][j] + tax * j)) ? min : dist[e][j] + tax * j;
        }
        cout << min << "\n";
    }

    return 0;
}