#include <iostream>
#include <vector>
#include <set>

using namespace std;

namespace algo {
    namespace ds {
        class DSU {
        private:
            vector<int> parent;
            vector<int> sz;
        public:
            DSU(int n) {
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

                if (sz[ra] < sz[rb]) {
                    int temp = ra;
                    ra = rb;
                    rb = temp;
                }

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

    int n;
    cin >> n;

    algo::ds::DSU dsu(n);

    if (n == 2) {
        cout << "1 2";
        return 0;
    }
    else {
        set<int> ret;
        set<int>::iterator it;
        vector<int> ans;
        for (int i = 0; i < n - 2; i++) {
            int a, b;
            cin >> a >> b;
            dsu.unite(a, b);
        }

        for (int i = 1; i <= n; i++) {
            if (ret.size() == 2) break;
            int num = dsu.find(i);
            it = ret.find(num);
            if (it == ret.end()) {
                ret.insert(num);
                ans.push_back(num);
            }
            
        }
        cout << ans[0] << " " << ans[1];
    }

    return 0;
}