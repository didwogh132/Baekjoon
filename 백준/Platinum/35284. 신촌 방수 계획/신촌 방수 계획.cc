#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int u, v;
    long long cost;
    bool operator <(const node& right) {
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

    for (int i = 1; i <= n; i++) {
        long long cost;
        cin >> cost;
        arr.push_back({ 0, i, cost });
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        long long cost;
        cin >> u >> v >> cost;
        arr.push_back({ u, v, cost });
    }

    sort(arr.begin(), arr.end());

    algo::ds::MST mst2(n);

    long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (cnt == n - 1) break;
        if (arr[i].u == 0 || arr[i].v == 0) continue;
        if (mst2.unite(arr[i].u, arr[i].v)) {
            ans += arr[i].cost;
            cnt++;
        }
    }

    long long ans_all = 0;
    int cnt2 = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (cnt2 == n) break;
        if (mst.unite(arr[i].u, arr[i].v)) {
            ans_all += arr[i].cost;
            cnt2++;
        }
    }

    if (ans_all < ans) ans = ans_all;

    cout << ans;

    return 0;
}