#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int v, e, p;
struct node {
    int num;
    int cost;
    bool operator <(const node& right) const {
        return cost > right.cost;
    }
};
vector<node> a[5001];
int dist[5001];
int ret_g, ret_ans, ans;

void dijkstra(int num) {
    memset(dist, 0x7f, sizeof(dist));
    priority_queue<node> pq;
    pq.push({ num, 0 });
    dist[num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.num] < now.cost) continue;

        for (int i = 0; i < a[now.num].size(); i++) {
            node next = a[now.num][i];
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

    cin >> v >> e >> p;

    for (int i = 0; i < e; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        a[from].push_back({ to,cost });
        a[to].push_back({ from, cost });
    }

    dijkstra(1);

    ans = dist[v];
    ret_g = dist[p];

    dijkstra(p);

    if (dist[v] == 0x7f7f7f7f) {
        cout << "GOOD BYE";
        return 0;
    }
    else {
        ret_ans = dist[v];
        if (ret_g + ret_ans > ans) {
            cout << "GOOD BYE";
        }
        else {
            cout << "SAVE HIM";
        }
    }

    return 0;
}