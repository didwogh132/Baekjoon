#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

namespace algo {
    namespace ds {
        class DSU {
        private:
            unordered_map<string, int> a;
            vector<int> parent;
            vector<int> sz;

            int getId(const string& name) {
                unordered_map<string, int>::iterator it = a.find(name);
                if (it != a.end()) return it->second;

                int id = parent.size();
                a[name] = id;
                parent.push_back(id);
                sz.push_back(1);
                return id;
            }

            int find(int x) {
                if (parent[x] == x) return x;
                parent[x] = find(parent[x]);
                return parent[x];
            }
        public:
            DSU(int n = 0) {
                if (n > 0) a.reserve(n);
            }

            int unite(string a, string b) {
                int x = getId(a);
                int y = getId(b);

                int rx = find(x);
                int ry = find(y);

                if (rx == ry) return sz[rx];

                if (sz[rx] < sz[ry]) {
                    int temp = rx;
                    rx = ry;
                    ry = temp;
                }

                parent[ry] = rx;
                sz[rx] += sz[ry];
                return sz[rx];
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
        algo::ds::DSU dsu(n * 2);
        for (int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;

            cout << dsu.unite(a, b) << "\n";
        }
    }
    return 0;
}