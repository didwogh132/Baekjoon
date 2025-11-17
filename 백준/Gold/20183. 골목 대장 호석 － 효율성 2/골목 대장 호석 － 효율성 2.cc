#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

int n, m, a, b, tax;
struct node {
    int num;
    long long cost;
    bool operator<(const node& right) const {
        if (cost != right.cost) return cost > right.cost;
        return false;
    }
};
vector<node> arr[100010];
long long dist[100010];

bool dijkstra(int num, int limit) {
    fill(dist, dist + n + 1, LLONG_MAX);
    priority_queue<node> pq;
    pq.push({ num, 0 });
    dist[num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            if (next.cost > limit) continue;
            long long nextcost = dist[now.num] + next.cost;
            if (dist[next.num] <= nextcost) continue;
            dist[next.num] = nextcost;
            pq.push({ next.num, nextcost });
        }
    }

    return dist[b] <= tax;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> a >> b >> tax;

    int max_cost = 0;

    for (int i = 0; i < m; i++) {
        int from, to;
        long long cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
        max_cost = (cost > max_cost) ? cost : max_cost;
    }
    int left = 0, right = max_cost;
    int ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (dijkstra(a, mid)) {
            right = mid - 1;
            ans = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}