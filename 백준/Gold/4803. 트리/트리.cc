#include <iostream>
#include <vector>

using namespace std;

namespace algo {
    namespace ds {
        class DSU {
        private:
            vector<int> parent;
            vector<int> sz;
            vector<int> nodeCnt;
            vector<int> edgeCnt;
        public:
            DSU(int n) {
                parent.resize(n + 1);
                sz.resize(n + 1, 1);
                nodeCnt.resize(n + 1, 1);
                edgeCnt.resize(n + 1, 0);
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

                if (ra == rb) {
                    edgeCnt[ra] += 1;
                    return;
                }

                if (sz[ra] < sz[rb]) {
                    int temp = ra;
                    ra = rb;
                    rb = temp;
                }

                parent[rb] = ra;
                sz[ra] += sz[rb];
                nodeCnt[ra] = nodeCnt[ra] + nodeCnt[rb];
                edgeCnt[ra] = edgeCnt[ra] + edgeCnt[rb] + 1;
            }

            bool isRoot(int x) {
                return parent[x] == x;
            }

            bool tree(int x) {
                return edgeCnt[x] == nodeCnt[x] - 1;
            }
        };
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int t = 1;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        algo::ds::DSU dsu(n);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            dsu.unite(a, b);
        }
        for (int i = 1; i <= n; i++) dsu.find(i);

        int treeCnt = 0;

        for (int i = 1; i <= n; i++) {
            if (dsu.isRoot(i)) {
                if (dsu.tree(i)) treeCnt++;
            }
        }

        cout << "Case " << t++ << ": ";
        if (treeCnt == 0) {
            cout << "No trees.\n";
        }
        else if (treeCnt == 1) {
            cout << "There is one tree.\n";
        }
        else {
            cout << "A forest of " << treeCnt << " trees.\n";
        }
        
    }
    return 0;
}