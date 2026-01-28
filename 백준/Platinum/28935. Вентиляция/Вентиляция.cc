#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace algo {
    namespace ds {
        class LCA {
        private:
            int n, log;

            vector<vector<int>> arr;
            vector<vector<int>> parent;
            vector<int> depth;

        public:
            LCA(int n) : n(n) {
                log = 1;
                while ((1 << log) <= n) log++;

                arr.assign(n + 1, vector<int>());
                parent.assign(n + 1, vector<int>(log, 0));
                depth.assign(n + 1, -1);
            }

            void init(int u, int v) {
                arr[u].push_back(v);
                arr[v].push_back(u);
            }

            void build(int root) {
                queue<int> q;
                q.push(root);
                parent[root][0] = 0;
                depth[root] = 0;

                while (!q.empty()) {
                    int now = q.front(); q.pop();

                    for (int i = 0; i < arr[now].size(); i++) {
                        int next = arr[now][i];

                        if (depth[next] == -1) {
                            depth[next] = depth[now] + 1;
                            parent[next][0] = now;
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

            int jump(int u, int up) {
                for (int k = 0; k < log; k++) {
                    if (up & (1 << k)) u = parent[u][k];
                }
                return u;
            }
            int query(int u, int v) {
                if (depth[u] < depth[v]) swap(u, v);

                int diff = depth[u] - depth[v];
                u = jump(u, diff);

                if (u == v) return u;

                for (int i = log - 1; i >= 0; i--) {
                    if (parent[u][i] != 0 && parent[u][i] != parent[v][i]) {
                        u = parent[u][i];
                        v = parent[v][i];
                    }
                }

                return parent[u][0];
            }

            int nextstep(int s, int t) {
                int w = query(s, t);

                if (w != s) {
                    return parent[s][0];
                }

                int diff = depth[t] - depth[s] - 1;
                return jump(t, diff);
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
        cin >> u >> v;
        lca.init(u, v);
    }

    lca.build(1);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        cout << lca.nextstep(u, v) << "\n";
    }
    return 0;
}