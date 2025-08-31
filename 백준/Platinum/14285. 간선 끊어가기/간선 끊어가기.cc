#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>

using namespace std;

int n, m, s, t;
struct edge {
    int num;
    int cost;
};
struct node {
    int num;
    int sum;
    int max;
    int sum_max;
    bool operator <(node right) const {
        return sum_max > right.sum_max;
    }
};
vector<edge> arr[5010];
int dist[5010];
int min_dist;
int max_cost;

void dijkstra(int num) {
    priority_queue<node> pq;
    pq.push({ num, 0, 0, 0 });
    dist[num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.num] < now.sum_max) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            edge next = arr[now.num][i];
            int sum = now.sum + next.cost;
            int max_cost;
            if (now.max > next.cost) {
                max_cost = now.max;
            }
            else {
                max_cost = next.cost;
            }
            int sum_max = sum - max_cost;
            if (dist[next.num] <= sum_max) continue;

            dist[next.num] = sum_max;
            pq.push({ next.num, sum, max_cost, sum_max });
        }
    }
}

int main() {
    cin >> n >> m;

    int ans = 0;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
        ans += cost;
    }
    fill(dist, dist + n + 1, INT_MAX);

    cin >> s >> t;

    dijkstra(s);

    ans -= dist[t];

    cout << ans;

    return 0;
}