#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

struct node {
    int num;
    int cost;
    bool operator < (node right) const {
        if (cost < right.cost) return false;
        if (cost > right.cost) return true;
        return false;
    }
};
vector<node> arr[20001];
int dist[20001];
int v, e;
int k;

void dijkstra(int start) {
    for (int i = 0; i <= v; i++) {
        dist[i] = 21e6;
    }
    priority_queue<node>pq;
    pq.push({ start, 0 });
    dist[start] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = dist[now.num] + next.cost;

            if (dist[next.num] > nextcost) {
                dist[next.num] = nextcost;
                pq.push({ next.num, nextcost });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> v >> e;
    cin >> k;
    for (int i = 0; i < e; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({to, cost});
    }
    dijkstra(k);

    for (int i = 1; i <= v; i++) {
        if (dist[i] == 21e6) {
            cout << "INF" << "\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }
    
    return 0;
}