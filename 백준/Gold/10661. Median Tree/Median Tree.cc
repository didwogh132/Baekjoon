#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int s, e, cost;
    bool operator<(const node& right) {
        if (cost != right.cost) return cost < right.cost;
        if (s != right.s) return s < right.s;
        if (e != right.e) return e < right.e;
        return false;
    }
};

namespace algo {
    namespace ds {
        class MST {
        private:
            vector<int> parent;
            vector<int> sz;
        public:
            MST(int n) {
                parent.resize(n + 1);
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

                if (sz[ra] < sz[rb]) {
                    int temp = ra;
                    ra = rb;
                    rb = temp;
                }
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
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)break;
        algo::ds::MST mst(n);

        vector<node> arr;
        vector<int> ans;
        arr.resize(m);
        for (int i = 0; i < m; i++) cin >> arr[i].s >> arr[i].e >> arr[i].cost;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < m; i++) {
            if (mst.unite(arr[i].s, arr[i].e)) {
                ans.push_back(arr[i].cost);
            }
        }

        cout << ans[ans.size() / 2] << "\n";
    }
    return 0;
}