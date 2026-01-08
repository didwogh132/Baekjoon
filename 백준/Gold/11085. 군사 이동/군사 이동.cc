#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int u, v, w;
};
namespace algo {
    namespace ds {
        class DSU {
        private:
            vector<int> parent;
            vector<int> sz;
        public:
            DSU(int n = 0) {
                parent.resize(n);
                sz.assign(n, 1);
                for (int i = 0; i < n; i++) parent[i] = i;
            }

            int find(int x) {
                if (parent[x] == x) return x;
                parent[x] = find(parent[x]);
                return parent[x];
            }

            bool unite(int a, int b) {
                int ra = find(a);
                int rb = find(b);
                if (ra == rb) return true;

                if (sz[ra] < sz[rb]) {
                    int temp = ra;
                    ra = rb;
                    rb = temp;
                }
                parent[rb] = ra;
                sz[ra] += sz[rb];
                return false;
            }
            bool same(int a, int b) {
                return find(a) == find(b);
            }
        };
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int p, w, c, v;
    cin >> p >> w >> c >> v;

    algo::ds::DSU dsu(p);

    vector<node> nodes;
    nodes.reserve(w);

    for (int i = 0; i < w; i++) {
        node e;
        cin >> e.u >> e.v >> e.w;
        nodes.push_back(e);
    }

    sort(nodes.begin(), nodes.end(), [](const node& a, const node& b) {
        return a.w > b.w;
        });

    for (int i = 0; i < w; i++) {
        dsu.unite(nodes[i].u, nodes[i].v);
        if (dsu.same(c, v)) {
            cout << nodes[i].w;
            return 0;
        }
    }
    return 0;
}