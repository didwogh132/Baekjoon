#include <iostream>
#include <vector>

using namespace std;

namespace algo {
    namespace ds {
        class UF {
        private:
            vector<int> parent, sz;
        public:
            UF(int n) {
                parent.resize(n + 1);
                sz.resize(n + 1, 1);

                for (int i = 0; i <= n; i++) parent[i] = i;
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

                if (sz[ra] < sz[rb]) swap(ra, rb);

                parent[rb] = ra;
                sz[ra] += sz[rb];
                return;
            }
        };
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    algo::ds::UF uf(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
    }

    vector<int> arr;
    arr.resize(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0;
    for (int i = 1; i < n; i++) {
        int ra = uf.find(arr[i - 1]);
        int rb = uf.find(arr[i]);

        if (ra != rb) ans++;
    }

    cout << ans;
    return 0;
}