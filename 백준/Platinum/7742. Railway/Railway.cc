#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct node {
    int to;
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

                parent.assign(n + 1, vector<int>(log, 0));
                depth.assign(n + 1, -1);
                arr.assign(n + 1, vector<node>());
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
                dist[root] = 0;
                depth[root] = 0;

                while (!q.empty()) {
                    int now = q.front(); q.pop();

                    for (int i = 0; i < arr[now].size(); i++) {
                        int next = arr[now][i].to;
                        int cost = dist[now] + arr[now][i].cost;
                        if (depth[next] == -1) {
                            depth[next] = depth[now] + 1;
                            parent[next][0] = now;
                            dist[next] = cost;
                            q.push(next);
                        }
                    }
                }

                for (int i = 0; i + 1 < log; i++) {
                    for (int v = 1; v <= n; v++) {
                        int mid = parent[v][i];
                        if (mid != 0) {
                            parent[v][i + 1] = parent[mid][i];
                        }
                    }
                }
            }

            int query(int u, int v) {
                if (depth[u] < depth[v]) swap(u, v);

                int diff = depth[u] - depth[v];

                for (int i = 0; i < log; i++) {
                    if (diff & (1 << i)) u = parent[u][i];
                }

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
        };
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    algo::ds::LCA lca(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        lca.init(u, v, cost);
    }

    lca.build(1);

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;

        cout << lca.dists(u, v) << "\n";
    }
    return 0;
}