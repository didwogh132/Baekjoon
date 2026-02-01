#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int u, v, day;
    bool operator<(const node& right) {
        return day < right.day;
    }
};
namespace algo {
    namespace ds {
        class UNION {
        private:
            vector<int> parent;
            vector<int> sz;

        public:
            UNION(int n) {
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

    algo::ds::UNION dsu(n);

    vector<node> arr;
    arr.reserve(m);
    int ans = 1;
    for (int i = 0; i < m; i++) {
        int u, v, day;
        cin >> u >> v >> day;
        arr.push_back({ u, v, day });
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < m; i++) {
        if (arr[i].day > ans) break;
        if (arr[i].day == ans) {
            if (!dsu.unite(arr[i].u, arr[i].v)) {
                break;
            }
            ans++;
            if (ans > n) break;
        }
    }

    cout << ans;
    return 0;
}