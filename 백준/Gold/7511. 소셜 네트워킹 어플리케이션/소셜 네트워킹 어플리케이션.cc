#include <iostream>
#include <vector>

using namespace std;

namespace algo {
    namespace ds {

        class DSU {
        private:
            vector<int> parent;
            vector<int> sz;

        public:
            DSU(int n = 0) { init(n); }

            void init(int n) {
                parent.assign(n, 0);
                sz.assign(n, 1);
                for (int i = 0; i < n; i++) parent[i] = i;
            }

            int find(int x) {
                if (parent[x] == x) return x;
                parent[x] = find(parent[x]);
                return parent[x];
            }

            void unite(int a, int b) {
                int ra = find(a);
                int rb = find(b);
                if (ra == rb) return;

                if (sz[ra] < sz[rb]) {
                    parent[ra] = rb;
                    sz[rb] += sz[ra];
                }
                else {
                    parent[rb] = ra;
                    sz[ra] += sz[rb];
                }
            }
        };
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {

        int n, k;
        cin >> n >> k;

        algo::ds::DSU dsu(n);

        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            dsu.unite(a, b);
        }
        int m;
        cin >> m;
        
        cout << "Scenario " << tc << ":" << "\n";

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            if (dsu.find(u) == dsu.find(v)) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}