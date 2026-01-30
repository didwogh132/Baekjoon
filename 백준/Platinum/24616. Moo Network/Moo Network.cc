#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    int x;
    int y;
    int id;
};
struct node {
    int u;
    int v;
    long long cost;
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

long long dist2(int x1, int x2, int y1, int y2) {
    long long dx = (long long)x1 - (long long)x2;
    long long dy = (long long)y1 - (long long)y2;
    return dx * dx + dy * dy;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    algo::ds::MST mst(n);
    vector<int> X(n), Y(n);
    vector<point> pts;
    pts.reserve(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        X[i] = x;
        Y[i] = y;
        pts.push_back({ x, y, i });
    }

    if (n <= 1) {
        cout << 0;
        return 0;
    }

    sort(pts.begin(), pts.end(), [](const point& a, const point& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
        });

    int lastseen[11];
    for (int y = 0; y <= 10; y++) lastseen[y] = -1;

    vector<node> arr;
    arr.reserve(11 * n);

    for (int i = 0; i < n; i++) {
        int id = pts[i].id;

        for (int y = 0; y <= 10; y++) {
            int j = lastseen[y];
            if (lastseen[y] != -1) {
                node e;
                e.u = id;
                e.v = j;
                e.cost = dist2(X[id], X[j], Y[id], Y[j]);
                arr.push_back(e);
            }
        }

        lastseen[pts[i].y] = id;
    }

    sort(arr.begin(), arr.end());

    long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (mst.unite(arr[i].u, arr[i].v)) {
            ans += arr[i].cost;
            cnt++;
            if (cnt == n - 1) break;
        }
    }

    cout << ans;
    return 0;
}