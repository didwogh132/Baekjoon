#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int v;
    long long cost;
};

namespace algo {
    namespace ds {
        class LCA {
        private:
            int n, log;

            vector<vector<node>> arr;
            vector<vector<int>> parent;
            vector<int> depth;
            vector<long long> dist;

        public:
            LCA(int n) : n(n) {
                log = 1;
                while ((1 << log) <= n) log++;

                arr.assign(n + 1, vector<node>());
                parent.assign(n + 1, vector<int>(log, 0));
                depth.assign(n + 1, -1);
                dist.assign(n + 1, 0);
            }

            void init(int u, int v, long long cost) {
                arr[u].push_back({ v, cost });
                arr[v].push_back({ u, cost });
            }

            void build(int root) {
                queue<int> q;
                q.push(root);
                parent[root][0] = 0;
                depth[root] = 0;
                dist[root] = 0;

                while (!q.empty()) {
                    int now = q.front(); q.pop();

                    for (int i = 0; i < arr[now].size(); i++) {
                        int next = arr[now][i].v;
                        long long cost = arr[now][i].cost;
                        if (depth[next] == -1) {
                            depth[next] = depth[now] + 1;
                            parent[next][0] = now;
                            dist[next] = dist[now] + cost;
                            q.push(next);
                        }
                    }
                }

                for (int i = 0; i + 1 < log; i++) {
                    for (int v = 1; v <= n; v++) {
                        int mid = parent[v][i];
                        if (mid != 0) parent[v][i + 1] = parent[mid][i];
                    }
                }
            }

            int lift(int x, int step) {
                for (int i = 0; i < log; i++) {
                    if ((step & (1 << i))) x = parent[x][i];
                }

                return x;
            }

            int query(int u, int v) {
                if (depth[u] < depth[v]) swap(u, v);

                int diff = depth[u] - depth[v];
                u = lift(u, diff);

                if (u == v) return u;

                for (int i = log - 1; i >= 0; i--) {
                    if (parent[u][i] != 0 && parent[u][i] != parent[v][i]) {
                        u = parent[u][i];
                        v = parent[v][i];
                    }
                }

                return parent[u][0];
            }

            long long dists(int u, int v) {
                int x = query(u, v);

                return dist[u] + dist[v] - 2 * dist[x];
            }

            int cnt(int u, int v, int k) {
                int x = query(u, v);

                int up = depth[u] - depth[x];
                int down = depth[v] - depth[x];

                if (k <= up + 1) {
                    return lift(u, k - 1);
                }

                int remain = k - (up + 1);

                return lift(v, down - remain);
            }
        };
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    algo::ds::LCA lca(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        long long cost;
        cin >> u >> v >> cost;
        lca.init(u, v, cost);
    }

    lca.build(1);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;

        if (num == 1) {
            int u, v;
            cin >> u >> v;
            cout << lca.dists(u, v) << "\n";
        }
        else {
            int u, v, k;
            cin >> u >> v >> k;

            cout << lca.cnt(u, v, k) << "\n";
        }
    }
    return 0;
}