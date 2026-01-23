#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int to;
    long long cost;
};

namespace algo {
    namespace ds {
        class LCA {
        private:
            int n;
            int log;
            
            vector<vector<node>> arr;
            vector<vector<int>> parent;
            vector<long long> dist;
            vector<int> depth;
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
                node e1 = { v, cost };
                node e2 = { u, cost };
                arr[u].push_back(e1);
                arr[v].push_back(e2);
            }

            void build(int root) {
                queue<int> q;
                q.push(root);
                depth[root] = 0;
                parent[root][0] = 0;
                dist[root] = 0;

                while (!q.empty()) {
                    int now = q.front(); q.pop();

                    for (int i = 0; i < arr[now].size(); i++) {
                        int next = arr[now][i].to;
                        long long cost = arr[now][i].cost;

                        if (depth[next] == -1) {
                            parent[next][0] = now;
                            depth[next] = depth[now] + 1;
                            dist[next] = dist[now] + cost;
                            q.push(next);
                        }
                    }
                }

                for (int j = 0; j < log; j++) {
                    for (int v = 1; v <= n; v++) {
                        int mid = parent[v][j];
                        if (mid != 0) parent[v][j + 1] = parent[mid][j];
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

                for (int j = log - 1; j >= 0; j--) {
                    if (parent[u][j] != 0 && parent[u][j] != parent[v][j]) {
                        u = parent[u][j];
                        v = parent[v][j];
                    }
                }

                return parent[u][0];
            }

            long long dists(int u, int v) {
                int a = query(u, v);
                return dist[u] + dist[v] - 2 * dist[a];
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
        int from, to, cost;
        cin >> from >> to >> cost;
        lca.init(from, to, cost);
    }

    lca.build(1);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        cout << lca.dists(u, v) << "\n";
    }
    return 0;
}