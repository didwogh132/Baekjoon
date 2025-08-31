#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int n, m, k;
struct node {
    int num;
    long long cost;
    bool operator <(node right) const {
        return cost > right.cost;
    }
};
vector<node> arr[100010];
long long dist[100010];
priority_queue<node>pq;

void dijkstra() {
    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            long long nextcost = dist[now.num] + next.cost;
            if (dist[next.num] <= nextcost) continue;
            dist[next.num] = nextcost;
            pq.push({ next.num, nextcost });
        }
    }
}

int main() {
    cin >> n >> m >> k;
    fill(dist, dist + n + 1, LLONG_MAX);
    
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[to].push_back({ from, cost });
    }
    
    for (int i = 0; i < k; i++) {
        int k_num;
        cin >> k_num;
        pq.push({ k_num, 0 });
        dist[k_num] = 0;
    }

    dijkstra();

    long long max = 0;
    int max_idx = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > max) {
            max = dist[i];
            max_idx = i;
        }
    }
    cout << max_idx << "\n" << max;
    
    return 0;
}