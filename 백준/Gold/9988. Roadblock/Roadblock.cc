#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct node {
    int num;
    int cost;
    int idx;
    bool operator<(const node& other) const {
        return cost > other.cost;
    }
};

int n, m;
vector<node> arr[251];
long long dist[251];
int parentNode[251];
int parentEdge[251];

void dijkstra(int doubledEdge, int saveParent) {
    for (int i = 1; i <= n; i++) {
        dist[i] = LLONG_MAX;
        if (saveParent == 1) {
            parentNode[i] = -1;
            parentEdge[i] = -1;
        }
    }

    priority_queue<node> pq;
    pq.push({ 1, 0, 0 });
    dist[1] = 0;

    while (!pq.empty()) {
        node now = pq.top(); 
        pq.pop();

        if (dist[now.num] < now.cost) continue;

        for (int i = 0; i < (int)arr[now.num].size(); i++) {
            node next = arr[now.num][i];

            long long edgeCost = next.cost;
            if (next.idx == doubledEdge) edgeCost *= 2;

            long long nextcost = now.cost + edgeCost;

            if (dist[next.num] <= nextcost) continue;

            dist[next.num] = nextcost;

            if (saveParent == 1) {
                parentNode[next.num] = now.num;
                parentEdge[next.num] = next.idx;
            }

            pq.push({ next.num, (int)nextcost, 0 });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost, i });
        arr[to].push_back({ from, cost, i });
    }

    dijkstra(0, 1);
    long long original = dist[n];

    vector<int> path;
    int cur = n;

    while (cur != 1) {
        path.push_back(parentEdge[cur]);
        cur = parentNode[cur];
    }

    long long answer = 0;

    for (int i = 0; i < (int)path.size(); i++) {
        dijkstra(path[i], 0);
        answer = max(answer, dist[n] - original);
    }

    cout << answer;
    return 0;
}