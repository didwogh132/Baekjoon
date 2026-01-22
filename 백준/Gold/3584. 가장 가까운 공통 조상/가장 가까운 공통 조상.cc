#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace algo {
    namespace ds {
        class LCA {
        private:
            int n;
            int log;

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

            void addnode(int u, int v) {
                arr[u].push_back(v);
                arr[v].push_back(u);
            }

            void build(int root) {
                for (int i = 1; i <= n; i++) depth[i] = -1;
                for (int i = 1; i <= n; i++) {
                    for (int j = 0; j < log; j++) {
                        parent[i][j] = 0;
                    }
                }
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

                for (int j = 0; j + 1 < log; j++) {
                    for (int v = 1; v <= n; v++) {
                        int mid = parent[v][j];
                        if (mid != 0) parent[v][j + 1] = parent[mid][j];
                    }
                }
            }

            int query(int u, int v) {
                if (depth[u] < depth[v]) swap(u, v);

                int diff = depth[u] - depth[v];
                for (int j = 0; j < log; j++) {
                    if (diff & (1 << j)) u = parent[u][j];
                }

                if (u == v) return u;

                for (int j = log - 1; j >= 0; j--) {
                    if (parent[u][j] != 0 && parent[u][j] != parent[v][j]) {
                        u = parent[u][j];
                        v = parent[v][j];
                    }
                }

                return parent[u][0];
            }
        };
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        algo::ds::LCA lca(n);

        vector<int> hasParent;
        hasParent.assign(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            lca.addnode(u, v);
            hasParent[v] = 1;
        }

        int root = 1;
        for (int i = 1; i <= n; i++) {
            if (hasParent[i] == 0) {
                root = i;
                break;
            }
        }
        lca.build(root);

        int u, v;
        cin >> u >> v;

        cout << lca.query(u, v) << "\n";
    }
    return 0;
}