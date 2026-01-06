#include <iostream>
#include <vector>
#include <algorithm>

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
                parent.assign(n + 1, 0);
                sz.assign(n + 1, 1);
                for (int i = 1; i <= n; i++) parent[i] = i;
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
            int size(int x) {
                int r = find(x);
                return sz[r];
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

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    }
    int c, h, k;
    cin >> c >> h >> k;

    int rc = dsu.find(c);
    int rh = dsu.find(h);

    vector<char> seen(n + 1, 0);
    vector<int> cand;

    for (int i = 1; i <= n; i++) {
        int r = dsu.find(i);
        if (seen[r]) continue;
        seen[r] = 1;

        if (r == rc) continue;
        if (r == rh) continue;

        cand.push_back(dsu.size(r));
    }

    sort(cand.begin(), cand.end(), greater<int>());

    long long ans = dsu.size(c);
    
    for (int i = 0; i < k; i++) {
        ans += cand[i];
    }

    cout << ans;
    return 0;
}