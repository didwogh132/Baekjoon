#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

struct node {
    int num;
    long long cost;
    int idx;
    bool operator<(const node& right) const {
        return cost > right.cost;
    }
};

int n, m;
vector<node> arr[101];
long long dist[101];
int path[101];

long long dijkstra(int block_idx, bool save_path) {
    priority_queue<node> pq;

    fill(dist, dist + n + 1, LLONG_MAX);
    if (save_path) fill(path, path + n + 1, 0);

    dist[1] = 0;
    pq.push({ 1, 0, -1 });

    while (!pq.empty()) {
        node now = pq.top();
        pq.pop();

        if (dist[now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];

            long long nextcost = next.cost;
            if (next.idx == block_idx) nextcost *= 2;

            if (dist[next.num] <= dist[now.num] + nextcost) continue;

            dist[next.num] = dist[now.num] + nextcost;

            if (save_path) {
                path[next.num] = now.num;
            }

            pq.push({ next.num, dist[next.num], next.idx });
        }
    }

    return dist[n];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        arr[from].push_back({ to, cost, i });
        arr[to].push_back({ from, cost, i });
    }

    long long origin = dijkstra(-1, true);

    vector<int> route;
    int now = n;

    while (now != 1) {
        int prev = path[now];

        for (int i = 0; i < arr[prev].size(); i++) {
            if (arr[prev][i].num == now) {
                route.push_back(arr[prev][i].idx);
                break;
            }
        }

        now = prev;
    }

    long long answer = 0;

    for (int i = 0; i < route.size(); i++) {
        long long result = dijkstra(route[i], false);
        answer = max(answer, result - origin);
    }

    cout << answer;
    return 0;
}