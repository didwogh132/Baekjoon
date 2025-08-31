#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int v, e;
int dist_mac[10010];
int dist_star[10010];
struct node {
    int num;
    int cost;
    bool operator <(node right) const {
        return cost > right.cost;
    }
};
vector<node> arr[10010];
priority_queue<node>mac_pq;
priority_queue<node>star_pq;
int m, x;
int s, y;

void dijkstra_mac() {
    while (!mac_pq.empty()) {
        node now = mac_pq.top(); mac_pq.pop();

        if (dist_mac[now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = dist_mac[now.num] + next.cost;

            if (dist_mac[next.num] <= nextcost) continue;
            dist_mac[next.num] = nextcost;
            mac_pq.push({ next.num, nextcost });
        }
    }
}
void dijkstra_star() {
    while (!star_pq.empty()) {
        node now = star_pq.top(); star_pq.pop();

        if (dist_star[now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = dist_star[now.num] + next.cost;

            if (dist_star[next.num] <= nextcost) continue;
            dist_star[next.num] = nextcost;
            star_pq.push({ next.num, nextcost });
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> v >> e;
    fill(dist_mac, dist_mac + v + 1, INT_MAX);
    fill(dist_star, dist_star + v + 1, INT_MAX);
    for (int i = 0; i < e; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
    }

    cin >> m >> x;
    for (int i = 0; i < m; i++) {
        int idx;
        cin >> idx;
        mac_pq.push({ idx, 0 });
        dist_mac[idx] = 0;
    }
    cin >> s >> y;
    for (int i = 0; i < s; i++) {
        int idx;
        cin >> idx;
        star_pq.push({ idx, 0 });
        dist_star[idx] = 0;
    }

    dijkstra_mac();
    dijkstra_star();
    
    int min_idx = 0;
    int min = INT_MAX;

    for (int i = 1; i <= v; i++) {
        if (dist_mac[i] == 0 || dist_star[i] == 0) continue;
        if (dist_mac[i] <= x && dist_star[i] <= y) {
            if (dist_mac[i] + dist_star[i] < min) {
                min_idx = i;
                min = dist_mac[i] + dist_star[i];
            }
        }
    }
    if (min == INT_MAX) {
        cout << -1;
    }
    else {
        cout << min;
    }


    return 0;
}