#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

int k, n, r;
struct node {
    int num;
    int line;
    int cost;
    bool operator <(const node& right) const {
        return line > right.line;
    }
};
vector<node> arr[101];
int dist[10001][101];

void dijkstra(int num) {
    priority_queue<node> pq;
    pq.push({ num, 0, 0 });
    dist[0][num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.cost][now.num] < now.line) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextline = now.line + next.line;
            int nextcost = now.cost + next.cost;

            if (nextcost > k) continue;
            if (dist[nextcost][next.num] <= nextline) continue;
            dist[nextcost][next.num] = nextline;
            pq.push({ next.num, nextline, nextcost });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> n >> r;

    for (int i = 0; i <= k; i++) {
        fill(dist[i], dist[i] + n + 1, INT_MAX);
    }

    for (int i = 0; i < r; i++) {
        int from, to, line, cost;
        cin >> from >> to >> line >> cost;
        arr[from].push_back({ to, line, cost });
    }

    dijkstra(1);

    int ans = INT_MAX;

    for (int i = 0; i <= k; i++) {
        ans = (dist[i][n] < ans) ? dist[i][n] : ans;
    }

    if (ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }
    return 0;
}