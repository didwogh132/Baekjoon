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
    namespace ds{
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

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int> (n));

    algo::ds::MST mst(n);
    vector<node> arr;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            arr.push_back({ i, j, a[i][j] });
        }
    }

    sort(arr.begin(), arr.end());

    long long sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (mst.unite(arr[i].s, arr[i].e)) {
            sum += arr[i].cost;
        }
    }

    cout << sum;

    return 0;
}