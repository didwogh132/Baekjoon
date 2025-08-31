#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>

#define Max 200010
#define mod 1000000007

using namespace std;

struct node {
    int from;
    int to;
    int cost;
    bool operator<(node right) const {
        return cost > right.cost;
    }
};
int n, m, w;
vector<node> arr;
int dist[505];

bool bellman(int start) {
    fill(dist, dist + n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < arr.size(); j++) {
            int from = arr[j].from;
            int to = arr[j].to;
            int cost = arr[j].cost;
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
            }
        }
    }
    for (int j = 0; j < arr.size(); j++) {
        int from = arr[j].from;
        int to = arr[j].to;
        int cost = arr[j].cost;
        if (dist[to] > dist[from] + cost) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        bool flag = false;
        cin >> n >> m >> w;

        for (int i = 0; i < m; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            arr.push_back({ from, to, cost });
            arr.push_back({ to, from, cost });
        }
        for (int i = 0; i < w; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            arr.push_back({ from,to, -cost });
        }

        flag = bellman(1);
        if (flag) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
        arr.clear();
    }

    return 0;
}