#include <iostream>
#include <vector>
#include <algorithm>
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
            vector<long long> dist;
            vector<int> depth;
        public:
            LCA(int n) : n(n) {
                log = 1;
                while ((1 << log) <= n) log++;

                arr.resize(n + 1);
                parent.resize(n + 1, vector<int>(log, 0));
                depth.resize(n + 1, -1);
                dist.resize(n + 1);
            }

            void init(int u, int v, long long cost) {
                arr[u].push_back({ v, cost });
                arr[v].push_back({ u, cost });
            }

            void build(int root) {
                queue<int> q;
                parent[root][0] = 0;
                depth[root] = 0;
                dist[root] = 0;
                q.push(root);

                while (!q.empty()) {
                    int now = q.front(); q.pop();

                    for (int i = 0; i < arr[now].size(); i++) {
                        int next = arr[now][i].v;
                        long long cost = arr[now][i].cost;
                        if (depth[next] == -1 || dist[next] > dist[now] + cost) {
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

            int query(int u, int v) {
                if (depth[u] < depth[v])swap(u, v);

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

    int n, m;
    cin >> n >> m;

    algo::ds::LCA lca(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        long long cost;
        char locate;
        cin >> u >> v >> cost >> locate;
        lca.init(u, v, cost);
    }

    lca.build(1);

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        cout << lca.dists(u, v) << "\n";
    }
    return 0;
}