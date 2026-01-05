#include <iostream>
#include <vector>

using namespace std;

namespace algo {
    namespace ds {

        class DSU {
        private:
            vector<int> parent;
            vector<int> sz;
            vector<long long> sum;

        public:
            DSU(int n = 0) {
                init(n);
            }

            void init(int n) {
                parent.assign(n + 1, 0);
                sz.assign(n + 1, 1);
                sum.assign(n + 1, 0);

                for (int i = 0; i <= n; i++) {
                    parent[i] = i;
                    sz[i] = 1;
                    sum[i] = 0;
                }
            }

            void set_value(int i, long long v) {
                sum[i] = v;
            }

            int find(int x) {
                if (parent[x] == x) return x;
                parent[x] = find(parent[x]);
                return parent[x];
            }

            long long Union(int a, int b) {
                int ra = find(a);
                int rb = find(b);

                if (ra == rb) {
                    return sum[ra];
                }

                if (sz[ra] < sz[rb]) {
                    parent[ra] = rb;
                    sz[rb] += sz[ra];
                    sum[rb] += sum[ra];
                    return sum[rb];
                }
                else {
                    parent[rb] = ra;
                    sz[ra] += sz[rb];
                    sum[ra] += sum[rb];
                    return sum[ra];
                }
            }
        };
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    algo::ds::DSU dsu(n);

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        dsu.set_value(i, x);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << dsu.Union(a, b) << "\n";
    }

    return 0;
}