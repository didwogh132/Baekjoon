#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int u, v, cost;
    bool operator<(const node& right) {
        return cost > right.cost;
    }
};

int ans[1001][1001];

namespace algo {
    namespace ds {
        class MST {
        private:
            vector<int> parent, sz;
            vector<vector<int>> members;

        public:
            MST(int n) {
                parent.resize(n + 1);
                sz.resize(n + 1, 1);
                members.resize(n + 1);
                for (int i = 0; i <= n; i++) {
                    parent[i] = i;
                    members[i].push_back(i);
                }
            }

            int find(int x) {
                if (parent[x] == x) return x;
                parent[x] = find(parent[x]);
                return parent[x];
            }

            void unite(int a, int b, int w) {
                int ra = find(a);
                int rb = find(b);

                if (ra == rb) return;

                if (sz[ra] < sz[rb]) swap(ra, rb);

                int i = 0;

                while (i < members[rb].size()) {
                    int x = members[rb][i];

                    int j = 0;
                    while (j < members[ra].size()) {
                        int y = members[ra][j];
                        ans[x][y] = w;
                        ans[y][x] = w;
                        j++;
                    }
                    i++;
                }

                i = 0;
                while (i < members[rb].size()) {
                    members[ra].push_back(members[rb][i]);
                    i++;
                }
                members[rb].clear();

                parent[rb] = ra;
                sz[ra] += sz[rb];

                return;
            }
        };
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<node> arr;
    arr.reserve(m);
    algo::ds::MST mst(n);
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        arr.push_back({ u, v, cost });
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        mst.unite(arr[i].u, arr[i].v, arr[i].cost);
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        cout << ans[a][b] << "\n";
    }
    return 0;
}