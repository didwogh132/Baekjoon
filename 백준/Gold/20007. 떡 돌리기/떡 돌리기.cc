#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m, x, y;
struct node {
    int num;
    int cost;
    bool operator <(node right) const {
        if (cost > right.cost) return true;
        if (cost < right.cost) return false;
        return false;
    }
};
vector<node> arr[1010];
int dist[1010];
void dijkstra(int num) {
    for (int i = 0; i < n; i++) {
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
    
    cin >> n >> m >> x >> y;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
    }
    dijkstra(y);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX || dist[i] * 2 > x) {
            cout << -1;
            return 0;
        }
        dist[i] *= 2;
    }
    sort(dist, dist + n);
    int cnt = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + dist[i] <= x) {
            sum += dist[i];
        }
        else {
            cnt++;
            sum = dist[i];
        }
    }
    cout << cnt;
    return 0;
}