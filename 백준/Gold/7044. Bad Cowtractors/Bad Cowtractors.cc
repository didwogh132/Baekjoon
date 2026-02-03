#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int s, e;
    long long cost;
    bool operator<(const node& a) {
        return cost > a.cost;
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
                if (parent[x] == x) return x;
                parent[x] = find(parent[x]);
                return parent[x];
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
        cin >> arr[i].s >> arr[i].e >> arr[i].cost;
    }

    sort(arr.begin(), arr.end());

    long long ans = 0;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (mst.unite(arr[i].s, arr[i].e)) {
            ans += arr[i].cost;
            cnt++;
        }
    }

    if (cnt != n - 1) cout << -1;
    else cout << ans;
    return 0;
}