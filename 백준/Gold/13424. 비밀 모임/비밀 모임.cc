#include <iostream>
#include <vector>
#include <cstring>
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
int n, m;
vector<node> arr[101];
int dist[101];
int visited[101];
vector<int> start;
int Min_cost;
int Min;

void dijkstra(int start) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    priority_queue<node> pq;
    pq.push({ start, 0 });
    dist[start] = 0;

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
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        memset(visited, 0, sizeof(visited));
        Min_cost = INT_MAX;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            arr[from].push_back({ to, cost });
            arr[to].push_back({ from, cost });
        }
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int s;
            cin >> s;
            start.push_back(s);
        }

        for (int i = 0; i < start.size(); i++) {
            dijkstra(start[i]);
            for (int j = 1; j <= n; j++) {
                visited[j] += dist[j];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (visited[i] < Min_cost) {
                Min_cost = visited[i];
                Min = i;
            }
        }
        cout << Min << "\n";

        start.clear();
        for (int i = 1; i <= n; i++) {
            arr[i].clear();
        }
    }
    
    return 0;
}