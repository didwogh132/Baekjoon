#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <cmath>
#include <queue>
#include <deque>
#include <climits>
#include <memory.h>
#include <stdio.h>
#include <iomanip>

#define MAX 1000010
#define MOD 1000000007

using namespace std;

struct node {
    int s, e, cost;
};
bool cmpup(node a, node b) {
    return a.cost < b.cost;
}
bool cmpdown(node a, node b) {
    return a.cost > b.cost;
}

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

            void build(int n) {
                for (int i = 0; i <= n; i++) {
                    parent[i] = i;
                    sz[i] = 1;
                }
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

    int n, m, k;

    while (true) {
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0) break;

        algo::ds::MST mst(n);
        vector<node> arr;
        for (int i = 0; i < m; i++) {
            char color;
            int s, e;
            cin >> color >> s >> e;
            if (color == 'R') {
                arr.push_back({ s, e, 0 });
            }
            else if (color == 'B') {
                arr.push_back({ s, e, 1 });
            }
        }
        int Bmin = 0, Bmax = 0;
        sort(arr.begin(), arr.end(), cmpup);
        for (int i = 0; i < m; i++) {
            if (mst.unite(arr[i].s, arr[i].e)) {
                Bmin += arr[i].cost;
            }
        }
        mst.build(n);
        sort(arr.begin(), arr.end(), cmpdown);
        for (int i = 0; i < m; i++) {
            if (mst.unite(arr[i].s, arr[i].e)) {
                Bmax += arr[i].cost;
            }
        }

        if (k >= Bmin && k <= Bmax) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
    return 0;
}