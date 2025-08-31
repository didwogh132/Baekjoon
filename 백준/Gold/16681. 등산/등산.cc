#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int n, m, d, e;
long long height[100010];
struct node {
    int num;
    long long cost;
    bool operator <(node right) const {
        return cost > right.cost;
    }
};
vector<node> arr[100010];
long long dist[100010];
long long dist2[100010];

void dijkstra(int num) {
    priority_queue<node> pq;
    pq.push({ num, 0 });
    dist[num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            long long nextcost = dist[now.num] + next.cost;

            if (dist[next.num] <= nextcost) continue;
            if (height[now.num] >= height[next.num]) continue;
            dist[next.num] = nextcost;
            pq.push({ next.num, nextcost });
        }
    }
}
void dijkstra2(int num) {
    priority_queue<node> pq;
    pq.push({ num, 0 });
    dist2[num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist2[now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            long long nextcost = dist2[now.num] + next.cost;

            if (dist2[next.num] <= nextcost) continue;
            if (height[now.num] >= height[next.num]) continue;
            dist2[next.num] = nextcost;
            pq.push({ next.num, nextcost });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> d >> e;

    for (int i = 1; i <= n; i++) {
        cin >> height[i];
    }

    fill(dist, dist + n + 1, LLONG_MAX);
    fill(dist2, dist2 + n + 1, LLONG_MAX);

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost * d });
        arr[to].push_back({ from, cost * d });
    }

    dijkstra(1);
    dijkstra2(n);
    long long Max = LLONG_MIN;

    for (int i = 2; i < n; i++) {
        if (dist[i] != LLONG_MAX) {
            dist[i] = height[i] * e - dist[i];
        }
        if (dist[i] != LLONG_MAX && dist2[i] != LLONG_MAX) {
            if (dist[i] - dist2[i] > Max) {
                Max = dist[i] - dist2[i];
            }
        }
    }

    if (Max == LLONG_MIN) {
        cout << "Impossible";
    }
    else {
        cout << Max;
    }

    return 0;
}