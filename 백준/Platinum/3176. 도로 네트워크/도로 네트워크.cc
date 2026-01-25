#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct node {
    int to;
    int cost;
};
struct node2 {
    int mn;
    int mx;
};

namespace algo {
    namespace ds {
        class LCA {
        private:
            int n;
            int log;

            vector<vector<node>> arr;
            vector<vector<int>>parent;
            vector<int> depth;
            vector<vector<int> > mn;
            vector<vector<int> > mx;
        public:
            LCA(int n) : n(n) {
                log = 1;
                while ((1 << log) <= n) log++;
                arr.assign(n + 1, vector<node>());
                parent.assign(n + 1, vector<int>(log, 0));
                depth.assign(n + 1, -1);
                mn.assign(n + 1, vector<int>(log, INT_MAX));
                mx.assign(n + 1, vector<int>(log, INT_MIN));
            }

            void init(int u, int v, int cost) {
                arr[u].push_back({ v, cost });
                arr[v].push_back({ u, cost });
            }

            void build(int root) {
                queue<int> q;
                q.push(root);
                parent[root][0] = 0;
                depth[root] = 0;
                mn[root][0] = INT_MAX;
                mx[root][0] = INT_MIN;

                while (!q.empty()) {
                    int now = q.front(); q.pop();

                    for (int i = 0; i < arr[now].size(); i++) {
                        int next = arr[now][i].to;
                        int cost = arr[now][i].cost;

                        if (depth[next] == -1) {
                            depth[next] = depth[now] + 1;
                            mn[next][0] = cost;
                            mx[next][0] = cost;
                            parent[next][0] = now;
                            q.push(next);
                        }
                    }
                }

                for (int j = 0; j < log-1; j++) {
                    for (int v = 1; v <= n; v++) {
                        int mid = parent[v][j];
                        if (mid != 0) {
                            parent[v][j + 1] = parent[mid][j];
                            mn[v][j + 1] = min(mn[v][j], mn[mid][j]);
                            mx[v][j + 1] = max(mx[v][j], mx[mid][j]);
                        }
                    }
                }
            }

            node2 query(int u, int v) {
                node2 ans;
                ans.mn = INT_MAX;
                ans.mx = INT_MIN;

                if (u == v) {
                    ans.mn = 0;
                    ans.mx = 0;
                    return ans;
                }

                if (depth[u] < depth[v]) swap(u, v);

                int diff = depth[u] - depth[v];
                for (int i = 0; i < log; i++) {
                    if (diff & (1 << i)) {
                        ans.mn = min(ans.mn, mn[u][i]);
                        ans.mx = max(ans.mx, mx[u][i]);
                        u = parent[u][i];
                    }
                }
                if (u == v) {
                    if (ans.mn == INT_MAX) ans.mn = 0;
                    if (ans.mx == INT_MIN) ans.mx = 0;
                    return ans;
                }

                for (int j = log - 1; j >= 0; j--) {
                    if (parent[u][j] != 0 && parent[u][j] != parent[v][j]) {
                        ans.mn = min(ans.mn, mn[u][j]);
                        ans.mx = max(ans.mx, mx[u][j]);

                        ans.mn = min(ans.mn, mn[v][j]);
                        ans.mx = max(ans.mx, mx[v][j]);
                        u = parent[u][j];
                        v = parent[v][j];
                    }
                }

                ans.mn = min(ans.mn, mn[u][0]);
                ans.mx = max(ans.mx, mx[u][0]);

                ans.mn = min(ans.mn, mn[v][0]);
                ans.mx = max(ans.mx, mx[v][0]);

                return ans;
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

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;

        node2 ans = lca.query(u, v);

        cout << ans.mn << " " << ans.mx << "\n";
    }

    return 0;
}