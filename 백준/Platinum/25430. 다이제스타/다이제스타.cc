#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <map>

using namespace std;

int n, m, a, b;
struct node {
    int num;
    long long cost;
    long long last_node;
    bool operator<(node right) const {
        return cost > right.cost;
    }
};
struct nodes {
    int from;
    int to;
};
map<int, vector<nodes>> arr;
vector<long long> d(50010, LLONG_MAX);
vector<long long> t(50010, LLONG_MAX);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[cost].push_back({ from, to });
    }

    cin >> a >> b;
    d[a] = 0;

    map<int, vector<nodes>>::iterator it;
    for (it = arr.begin(); it != arr.end(); it++) {
        int cost = it->first;
        vector<nodes> edges = it->second;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].from;
            int v = edges[i].to;
            if (d[v] != LLONG_MAX) {
                if (t[u] > d[v] + cost) {
                    t[u] = d[v] + cost;
                }
            }
            if (d[u] != LLONG_MAX) {
                if (t[v] > d[u] + cost) {
                    t[v] = d[u] + cost;
                }
            }
        }

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].from;
            int v = edges[i].to;

            if (d[u] > t[u]) d[u] = t[u];
            if (d[v] > t[v]) d[v] = t[v];

            t[u] = LLONG_MAX;
            t[v] = LLONG_MAX;
        }
    }

    if (d[b] == LLONG_MAX) {
        cout << "DIGESTA";
    }
    else {
        cout << d[b];
    }
    return 0;
}