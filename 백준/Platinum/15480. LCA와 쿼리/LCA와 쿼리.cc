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

                parent.assign(n + 1, vector<int>(log, 0));
                arr.assign(n + 1, vector<int>());
                depth.assign(n + 1, -1);
            }

            void init(int u, int v) {
                arr[u].push_back(v);
                arr[v].push_back(u);
            }

            void build(int root) {
                queue<int> q;
                parent[root][0] = 0;
                depth[root] = 0;
                q.push(root);

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

            int query(int u, int v) {
                if (depth[u] < depth[v]) swap(u, v);

                int diff = depth[u] - depth[v];
                for (int i = 0; i < log; i++) {
                    if (diff & (1 << i)) u = parent[u][i];
                }

                if (u == v) return u;

                for (int i = log -1; i >= 0; i--) {
                    if (parent[u][i] != 0 && parent[u][i] != parent[v][i]) {
                        u = parent[u][i];
                        v = parent[v][i];
                    }
                }

                return parent[u][0];
            }

            bool cmp(int u, int v) {
                return depth[u] >= depth[v];
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
        int a, b, c;
        cin >> a >> b >> c;
        int result = lca.query(a, b);
        int temp = lca.query(b, c);
        if (!lca.cmp(result, temp)) {
            result = temp;
        }
        temp = lca.query(a, c);
        if (!lca.cmp(result, temp)) {
            result = temp;
        }

        cout << result << "\n";
    }
    return 0;
}