#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int n, m, r;
int idx[101];
struct node {
    int num;
    int cost;
    bool operator <(node right) const {
        if (cost > right.cost) return true;
        if (cost < right.cost) return false;
        return false;
    }
};
vector<node> arr[101];
int dist[101][101];

void dijkstra(int num) {
    priority_queue<node> pq;
    pq.push({ num, 0 });
    dist[num][num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[num][now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = dist[num][now.num] + next.cost;
            if (dist[num][next.num] <= nextcost) continue;
            dist[num][next.num] = nextcost;
            pq.push({ next.num, nextcost });
        }
    }
}

int main() {
    
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        fill(dist[i], dist[i] + n + 1, INT_MAX);
    }
    for (int i = 1; i <= n; i++) {
        cin >> idx[i];
    }
    for (int i = 0; i < r; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
    }
    int Max = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        dijkstra(i);

        for (int j = 1; j <= n; j++) {
            if (dist[i][j] <= m) {
                sum += idx[j];
            }
        }
        if (sum > Max) Max = sum;
    }

    cout << Max;

    return 0;
}