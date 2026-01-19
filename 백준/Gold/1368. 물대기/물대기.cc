#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int s, e, cost;
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
                parent.resize(n);
                sz.resize(n, 1);

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
                if (ra == rb) return false;

                if (sz[ra] > sz[rb]) {
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

    int n;
    cin >> n;
    algo::ds::MST mst(n + 1);

    vector<int> arr;
    vector<vector<int>> a(n, vector<int>(n));
    vector<node> m;
    arr.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        m.push_back({ 0, i, arr[i] });
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            m.push_back({ i + 1, j + 1, a[i][j] });
        }
    }

    sort(m.begin(), m.end());

    int sum = 0;
    for (int i = 0; i < m.size(); i++) {
        if (mst.unite(m[i].s, m[i].e)) {
            sum += m[i].cost;
        }
    }

    cout << sum;

    return 0;
}