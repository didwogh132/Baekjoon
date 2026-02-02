#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int s, e;
    long long cost;
    bool operator<(const node& right) {
        return cost < right.cost;
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

    vector<char> school;
    vector<node> arr;

    school.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> school[i];
    }

    for (int i = 0; i < m; i++) {
        int s, e;
        long long cost;
        cin >> s >> e >> cost;
        arr.push_back({ s, e, cost });
    }

    sort(arr.begin(), arr.end());
    
    int cnt = 0;
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        if (school[arr[i].s] != school[arr[i].e]) {
            if (mst.unite(arr[i].s, arr[i].e)) {
                ans += arr[i].cost;
                cnt++;
            }
        }
    }

    if (cnt != n-1) {
        cout << -1;
        return 0;
    }
    else {
        cout << ans;
    }

    return 0;
}