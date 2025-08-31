#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct node {
    int num;
    long long cost;
    bool operator<(node right) const {
        return cost < right.cost; // 최대힙처럼 사용하기 위해 반대 비교
    }
};

vector<node> arr[100010];
long long dist[100010];
int visited[100010];
vector<int> visits;
int n, m;

void dijkstra(int start) {
    priority_queue<node> pq;
    pq.push({ start, INT_MAX });
    dist[start] = INT_MAX;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.num] > now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            long long newCost = min(dist[now.num], next.cost);
            if (dist[next.num] < newCost) {
                dist[next.num] = newCost;
                visited[next.num] = now.num;
                pq.push({ next.num, newCost });
            }
        }
    }
}

int main() {
    memset(visited, -1, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back({ to, cost });
        arr[to].push_back({ from, cost });
    }
    int a, b;
    cin >> a >> b;

    dijkstra(a);

    cout << dist[b] << endl;
    return 0;
}