#include <iostream>
#include <cstring>
#include <string>
#include <climits>
#include <queue>
#include <iomanip>

using namespace std;

int n, k;
string arr[51];
long long dist[51][51];
struct node {
    int num;
    long long cost;
    int k;
    bool operator <(node right) const {
        return cost > right.cost;
    }
};

void dijkstra(int num) {
    for (int i = 0; i <= k; i++) {
        fill(dist[i], dist[i] + n, LLONG_MAX);
    }
    priority_queue<node> pq;
    pq.push({ num, 0, k });
    dist[k][num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.k][now.num] < now.cost) continue;

        for (int i = 0; i < n; i++) {
            if (i == now.num) continue;
            int next = i;
            int w = (int)(arr[now.num][i] - '0');

            long long nextcost = now.cost + (long long)2 * w;

            if (dist[now.k][next] > nextcost) {
                dist[now.k][next] = nextcost;
                pq.push({ next, nextcost, now.k });
            }

            if (now.k > 0) {
                long long nextcost2 = now.cost + (long long)w;
                if (dist[now.k - 1][next] > nextcost2) {
                    dist[now.k - 1][next] = nextcost2;
                    pq.push({ next, nextcost2, now.k - 1 });
                }

            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dijkstra(0);


    long long ans = LLONG_MAX;
    for (int i = 0; i <= k; i++) {
        if (dist[i][1] < ans) {
            ans = dist[i][1];
        }
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(10) << (ans / 2.0);

    return 0;
}