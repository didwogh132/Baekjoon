#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int u, v, cost;
    bool operator<(const node& right) {
        return cost < right.cost;
    }
};

namespace algo {
    namespace ds {
        class MST {
        private:
            vector<int> parent, sz;
        public:
            MST(int n) {
                parent.resize(n + 1);
                sz.resize(n + 1, 1);

                for (int i = 0; i <= n; i++) parent[i] = i;
            }

            int find(int x) {
                int root = x;
                while (parent[root] != root) root = parent[root];
                while (x != root) {
                    int p = parent[x];
                    parent[x] = root;
                    x = p;
                }
                return root;
            }

            bool unite(int a, int b) {
                int ra = find(a);
                int rb = find(b);

                if (ra == rb) return false;

                if (sz[ra] < sz[rb]) swap(ra, rb);

                parent[rb] = ra;
                sz[ra] += sz[rb];
                return true;
            }
        };
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    algo::ds::MST mst(n);
    vector<node> arr;
    arr.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> arr[i].u >> arr[i].v >> arr[i].cost;
    }

    sort(arr.begin(), arr.end());

    int Max = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (mst.unite(arr[i].u, arr[i].v)) {
            Max = (Max > arr[i].cost) ? Max : arr[i].cost;
        }
    }

    cout << Max;
    return 0;
}