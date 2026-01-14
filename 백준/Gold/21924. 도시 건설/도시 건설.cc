#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int s;
    int e;
    long long cost;
    bool operator<(const node& right) {
        if (cost < right.cost) return true;
        if (cost > right.cost) return false;

        if (s < right.s) return true;
        if (s > right.s) return false;

        if (e < right.e) return true;
        if (e > right.e) return false;
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
    cin >> n >> m;

    algo::ds::MST mst(n);

    vector<node> a;
    a.resize(m);
    long long sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i].s >> a[i].e >> a[i].cost;
        sum += a[i].cost;
    }
    sort(a.begin(), a.end());
    
    long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (mst.unite(a[i].s, a[i].e)) {
            ans += a[i].cost;
            cnt++;
        }
    }

    if (cnt == n-1) {
        cout << sum - ans;
    }
    else {
        cout << -1;
    }
    return 0;
}