#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct point {
    double x;
    double y;
};

struct node {
    int s;
    int e;
    double cost;
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

    int n;
    cin >> n;

    algo::ds::MST mst(n);
    vector<point> a;
    vector<node> arr;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

    for (int i = 0; i < n -1; i++) {
        for (int j = i + 1; j < n; j++) {
            double cost = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
            arr.push_back({ i, j, cost });
        }
    }

    sort(arr.begin(), arr.end());
    double sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (mst.unite(arr[i].s, arr[i].e)) {
            sum += arr[i].cost;
        }
    }

    cout << fixed << setprecision(2) << sum;
    return 0;
}