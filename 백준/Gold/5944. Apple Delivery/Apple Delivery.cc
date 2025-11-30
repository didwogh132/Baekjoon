#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

struct node {
    int num;
    int cost;
    bool operator <(const node& right) const {
        return cost > right.cost;
    }
};
vector<node> arr[100010];
int dist[100010];
int c, p, pb, pa1, pa2;
int ans = 0;

void dijkstra(int num) {
    memset(dist, 0x7f, sizeof(dist));
    priority_queue<node> pq;
    pq.push({ num, 0 });
    dist[num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = now.cost + next.cost;

            if (dist[next.num] <= nextcost) continue;
            dist[next.num] = nextcost;
            pq.push({ next.num, nextcost });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> c >> p >> pb >> pa1 >> pa2;

    for (int i = 0; i < c; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
    }

    dijkstra(pa1);

    int ret = 0;

    if (dist[pb] != 0x7f7f7f7f && dist[pa2] != 0x7f7f7f7f) {
        ret = dist[pb] + dist[pa2];
    }

    dijkstra(pa2);

    if (dist[pb] != 0x7f7f7f7f && dist[pa1] != 0x7f7f7f7f) {
        ans = dist[pb] + dist[pa1];
    }

    if (ret == 0 && ans == 0) {
        cout << -1;
    }
    else if (ret == 0) {
        cout << ans;
    }
    else if (ans == 0) {
        cout << ret;
    }
    else {
        ans = (ans < ret) ? ans : ret;
        cout << ans;
    }

    return 0;
}