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
    bool operator<(node right) const {
        if (cost > right.cost) return true;
        if (cost < right.cost) return false;
        return false;
    }
};
vector<node> arr[21];
int visited[21];
vector<int> visits;
int dist[21];
int n, m;

void dijkstra(int start) {
    for (int i = 0; i < n; i++) {
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
            visited[next.num] = now.num;
            pq.push({ next.num, nextcost });
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        memset(visited, -1, sizeof(visited));
        visits.clear();
        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            arr[from].push_back({ to, cost });
            arr[to].push_back({ from, cost });
        }

        dijkstra(0);


        if (visited[n - 1] == -1) {
            cout << "Case #" << tc << ": " << visited[n-1] << "\n";
        }
        else {
            visits.push_back(n-1);
            for (int i = n - 1; visited[i] != -1; ) {
                visits.push_back(visited[i]);
                i = visited[i];
            }
            reverse(visits.begin(), visits.end());
            cout << "Case #" << tc << ": ";
            for (int i = 0; i < visits.size(); i++) {
                cout << visits[i] << " ";
            }
            cout << "\n";
        }
        for (int i = 0; i < n; i++) {
            arr[i].clear();
        }
    }
    return 0;
}