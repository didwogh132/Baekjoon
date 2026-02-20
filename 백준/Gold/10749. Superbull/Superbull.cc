#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int u, v;
    long long cost;
    bool operator <(const node& right) {
        return cost > right.cost;
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

    int n;
    cin >> n;

    vector<long long> num;
    vector<node> arr;
    algo::ds::MST mst(n);

    num.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n; j++) {
            long long cost = num[i] ^ num[j];
            arr.push_back({ i, j, cost });
        }
    }

    sort(arr.begin(), arr.end());
    long long sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (mst.unite(arr[i].u, arr[i].v)) {
            sum += arr[i].cost;
        }
    }

    cout << sum;
    return 0;
}