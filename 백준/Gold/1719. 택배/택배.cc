#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int n, m;
int dist[201][201];
int visited[201][201];
struct node {
    int num;
    int cost;
    bool operator <(node right) const {
        return cost > right.cost;
    }
};
vector<node> arr[201];

void dijkstra(int num) {
    for (int i = 1; i <= n; i++) {
        dist[num][i] = INT_MAX;
    }
    priority_queue<node> pq;
    pq.push({ num, 0 });
    dist[num][num] = 0;
    visited[num][num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[num][now.num] < now.cost) continue;
        
        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = dist[num][now.num] + next.cost;
            if (dist[num][next.num] <= nextcost) continue;
            dist[num][next.num] = nextcost;
            if (now.num == num) {
                visited[num][next.num] = next.num;
            }
            else {
                visited[num][next.num] = visited[num][now.num];
            }
            pq.push({ next.num, nextcost });
        }
    }
}

int main() {

    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
    }
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) 
            {
                cout << "- ";
            }
            else 
            {
                cout << visited[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}