#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct node {
    int num;
    int cost;
    bool operator <(node right) const {
        if (cost > right.cost) return true;
        if (cost < right.cost) return false;
        return false;
    }
};
int n, v, e;
int a, b;
int num[101];
int dist[1001];
vector<node> arr[1001];
int sum;

void dijkstra(int num) {
    for (int i = 1; i <= v; i++) {
        dist[i] = INT_MAX;
    }
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
            dist[next.num] = nextcost;

            pq.push({ next.num, nextcost });
        }
    }
}


int main() {
    
    cin >> n >> v >> e;
    
    cin >> a >> b;
    
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < e; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
    }

    for (int i = 0; i < n; i++) {
        int kist_cost, food_cost;
        dijkstra(num[i]);
        if (dist[a] == INT_MAX) {
            kist_cost = -1;
        }
        else {
            kist_cost = dist[a];
        }
        if (dist[b] == INT_MAX) {
            food_cost = -1;
        }
        else {
            food_cost = dist[b];
        }
        sum += kist_cost + food_cost;
    }

    cout << sum;
    return 0;
}