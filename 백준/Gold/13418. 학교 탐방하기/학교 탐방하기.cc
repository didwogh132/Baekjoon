#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int s, e, cost;
    bool operator<(const node& right) {
        if (cost != right.cost) return cost < right.cost;
        if (s != right.s) return s < right.s;
        return e < right.e;
    }
};
struct node2 {
    int s, e, cost;
    bool operator<(const node2& right) {
        if (cost != right.cost) return cost > right.cost;
        if (s != right.s) return s < right.s;
        return e < right.e;
    }
};

namespace algo {
    namespace ds {
        class MST {
        private:
            vector<int> parent;
            vector<int> parent2;
            vector<int> sz;
            vector<int> sz2;
        public:
            MST(int n) {
                parent.resize(n +1);
                parent2.resize(n + 1);
                sz.resize(n+ 1, 1);
                sz2.resize(n + 1, 1);
                for (int i = 0; i <= n; i++) {
                    parent[i] = i;
                    parent2[i] = i;
                }
            }
            int find(int x, bool flag) {
                if (flag) {
                    if (parent[x] == x) return x;
                    parent[x] = find(parent[x], flag);
                    return parent[x];
                }
                else {
                    if (parent2[x] == x) return x;
                    parent2[x] = find(parent2[x], flag);
                    return parent2[x];
                }
            }
            bool unite(int a, int b, bool flag) {
                if (flag) {
                    int ra = find(a, flag);
                    int rb = find(b, flag);

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
                else {
                    int ra = find(a, flag);
                    int rb = find(b, flag);

                    if (ra == rb) return false;

                    if (sz2[ra] < sz2[rb]) {
                        int temp = ra;
                        ra = rb;
                        rb = temp;
                    }
                    parent2[rb] = ra;
                    sz2[ra] += sz2[rb];
                    return true;
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

    algo::ds::MST mst(n);

    vector<node> arr;
    vector<node2> arr2;
    for (int i = 0; i <= m; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        arr.push_back({ s, e, cost });
        arr2.push_back({ s, e, cost });
    }

    sort(arr.begin(), arr.end());
    sort(arr2.begin(), arr2.end());

    int cnt = 0;
    int cnt2 = 0;
    for (int i = 0; i <= m; i++) {
        if (mst.unite(arr[i].s, arr[i].e, true)) {
            if (arr[i].cost == 0) cnt++;
        }
        if (mst.unite(arr2[i].s, arr2[i].e, false)) {
            if (arr2[i].cost == 0) cnt2++;
        }
    }
    int ans = cnt * cnt - cnt2 * cnt2;

    cout << ans;
    return 0;
}