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
            DSU(int n) {
                parent.resize(n + 1, 0);
                sz.resize(n + 1, 1);
                for (int i = 0; i <= n; i++) parent[i] = i;
            }

            int find(int x) {
                if (parent[x] == x) return x;
                parent[x] = find(parent[x]);
                return parent[x];
            }

            bool unite(int a, int b) {
                int ra = find(a);
                int rb = find(b);
                if (ra == rb) return false;
                if (sz[a] < sz[b]) {
                    int temp = rb;
                    rb = ra;
                    ra = temp;
                }
                parent[rb] = ra;
                sz[ra] += sz[rb];
                return true;
            }

            bool isRoot(int x) {
                return parent[x] == x;
            }
        };
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int redundant = 0;

    algo::ds::DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (!dsu.unite(a, b)) redundant++;
    }

    for (int i = 1; i <= n; i++) dsu.find(i);

    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (dsu.isRoot(i)) k++;
    }

    cout << redundant + (k - 1);
    return 0;
}