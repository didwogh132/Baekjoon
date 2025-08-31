#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>

#define Max 1000010

using namespace std;

int n;
int arr[101][101];
int dist[101][101];
int visited[101][101];
struct node {
    int num;
    int cost;

    bool operator <(node right) const {
        return cost > right.cost;
    }
};

void dijkstra(int num) {
    priority_queue<node> pq;
    pq.push({ num, 0 });
    dist[num][num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[num][now.num] < now.cost) continue;

        for (int i = 0; i < n; i++) {
            if (arr[now.num][i] == 1) {
                int next = i;
                int nextcost = now.cost + 1;
                if (dist[num][next] <= nextcost) {
                    visited[num][next] = 1;
                    continue;
                }
                dist[num][next] = nextcost;
                visited[num][next] = 1;
                pq.push({ next, nextcost });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> n;

    for (int i = 0; i < n; i++) {
        fill(dist[i], dist[i] + n + 1, INT_MAX);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        dijkstra(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}