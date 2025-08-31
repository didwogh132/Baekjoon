#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int n, m;
int a, b, c;
struct node {
    int num;
    int cost;
    bool operator < (node right) const {
        if (cost > right.cost) return true;
        if (cost < right.cost) return false;
        return false;
    }
};
vector<node> arr[100010];
int idx[3];
int dist[3][100010];

void dijkstra(int num, int idx) {
    priority_queue<node> pq;
    pq.push({ num, 0 });
    dist[idx][num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[idx][now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = dist[idx][now.num] + next.cost;
            if (dist[idx][next.num] <= nextcost) continue;
            dist[idx][next.num] = nextcost;
            pq.push({ next.num, nextcost });
        }
    }
}

int main() {

    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> idx[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
    }
    
    for (int i = 0; i < 3; i++) {
        fill(dist[i], dist[i] + n + 1, INT_MAX);
        dijkstra(idx[i], i);
    }

    int Max = 0;
    int idxs = 0;
    for (int i = 1; i <= n; i++) {
        int Min = INT_MAX;
        if (i != idx[0] && i != idx[1] && i != idx[2]) {
            if (dist[0][i] < Min || dist[1][i] < Min || dist[2][i] < Min) {
                if (dist[0][i] <= dist[1][i] && dist[0][i] <= dist[2][i]) {
                    Min = dist[0][i];
                }
                else if (dist[1][i] <= dist[0][i] && dist[1][i] <= dist[2][i]) {
                    Min = dist[1][i];
                }
                else {
                    Min = dist[2][i];
                }
            }
            if (Min > Max) {
                Max = Min;
                idxs = i;
            }
        }
    }

    cout << idxs;

    return 0;
}