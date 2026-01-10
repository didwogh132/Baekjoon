#include <iostream>
#include <vector>
#include <set>

using namespace std;

namespace algo {
    namespace ds {
        class DSU {
        private:
            vector<int> parent;
            vector<int> rnk;
        public:
            DSU(int n) {
                parent.resize(n + 1);
                rnk.resize(n + 1, 0);
                for (int i = 0; i <= n; i++) parent[i] = i;
            }

            int find(int x) {
                if (parent[x] == x) return x;
                parent[x] = find(parent[x]);
                return parent[x];
            }

            void unite(int a, int b) {
                a = find(a);
                b = find(b);
                if (a == b) return;

                if (rnk[a] < rnk[b]) {
                    parent[a] = b;
                }
                else if (rnk[a] > rnk[b]) {
                    parent[b] = a;
                }
                else {
                    parent[b] = a;
                    rnk[a]++;
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
    vector<vector<int>> enemy;
    enemy.resize(n + 1);
    for (int i = 0; i < m; i++) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == 'F') {
            dsu.unite(a, b);
        }
        else {
            enemy[a].push_back(b);
            enemy[b].push_back(a);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (enemy[i].size() <= 1) continue;

        int base = enemy[i][0];
        for (int j = 1; j < enemy[i].size(); j++) {
            dsu.unite(base, enemy[i][j]);
        }
    }

    set<int> roots;

    for (int i = 1; i <= n; i++) {
        roots.insert(dsu.find(i));
    }
    cout << roots.size();

    return 0;
}