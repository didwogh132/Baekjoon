#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

int n, m;
struct node {
    int num;
    int cost;
    bool operator <(const node& right) const {
        if (cost != right.cost) return cost > right.cost;
        return false;
    }
};
vector<node> arr[100010];
int x, y, z;
int dist[100010];
void dijkstra(int num, bool flag) {
    fill(dist, dist + n + 1, INT_MAX);
    priority_queue<node> pq;
    pq.push({ num, 0 });
    dist[num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.num] < now.cost) continue;


        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = dist[now.num] + next.cost;

            if (dist[next.num] <= nextcost) continue;
            if (flag) {
                if (next.num == y) continue;
            }
            dist[next.num] = nextcost;
            pq.push({ next.num, nextcost });
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
    }

    cin >> x >> y >> z;

    int ans_mid = INT_MAX;
    int ans = INT_MAX;
    bool flag = false;

    dijkstra(x, true);
    ans = dist[z];

    dijkstra(x, false);
    if (dist[y] == INT_MAX) {
        flag = true;
    }
    else {
        ans_mid = dist[y];
    }
    dijkstra(y, false);
    if (dist[z] == INT_MAX) {
        flag = true;
    }
    else {
        ans_mid += dist[z];
    }

    if (flag) {
        cout << -1 << " ";
    }
    else {
        cout << ans_mid << " ";
    }

    if (ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}