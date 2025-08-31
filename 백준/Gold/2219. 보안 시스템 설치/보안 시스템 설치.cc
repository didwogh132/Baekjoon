#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>

using namespace std;

int n, m;
struct node {
    int num;
    int cost;
    bool operator <(node right) const {
        return cost > right.cost;
    }
};
vector<node> arr[202];
int dist[202][202];

void dijkstra(int num) {
    priority_queue<node> pq;
    pq.push({ num, 0 });
    dist[num][num] = 0;
    
    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[num][now.num] < now.cost) continue;
        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = dist[num][now.num] + arr[now.num][i].cost;

            if (dist[num][next.num] <= nextcost) continue;
            dist[num][next.num] = nextcost;
            pq.push({ next.num, nextcost });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
    }

    int Min = INT_MAX;
    int min_idx;
    for (int i = 1; i <= n; i++) {
        fill(dist[i], dist[i] + n + 1, INT_MAX);
    }

    for (int i = 1; i <= n; i++) {
        int sum = 0;

        dijkstra(i);
        for (int j = 1; j <= n; j++) {
            sum += dist[i][j];
        }
        if (sum < Min) {
            min_idx = i;
            Min = sum;
        }
    }

    cout << min_idx;

    return 0;
}