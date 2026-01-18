#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int idx, x, y, z;
    bool operator<(const node& right) {
        if (x != right.x) return x < right.x;
        if (y != right.y) return y < right.y;
        return z < right.z;
    }
};
struct edge {
    int s, e;
    int cost;
    bool operator<(const edge& right) {
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

    vector<node> arr;
    algo::ds::MST mst(n);

    for (int i = 0; i < n; i++) {
        node a;
        cin >> a.x >> a.y >> a.z;
        arr.push_back({i, a.x, a.y, a.z});
    }

    vector<node> vx = arr;
    vector<node> vy = arr;
    vector<node> vz = arr;
    vector<edge> edges;

    sort(vx.begin(), vx.end(), [](const node& a, const node& b) {
        return a.x < b.x;
        });
    sort(vy.begin(), vy.end(), [](const node& a, const node& b) {
        return a.y < b.y;
        });
    sort(vz.begin(), vz.end(), [](const node& a, const node& b) {
        return a.z < b.z;
        });

    
    for (int i = 0; i < n-1; i++) {
        edge e1;
        e1.s = vx[i].idx;
        e1.e = vx[i + 1].idx;
        e1.cost = min(abs(vx[i].x - vx[i+1].x), min(abs(vx[i].y - vx[i + 1].y), abs(vx[i].z - vx[i + 1].z)));
        edges.push_back(e1);

        edge e2;
        e2.s = vy[i].idx;
        e2.e = vy[i + 1].idx;
        e2.cost = min(abs(vy[i].x - vy[i + 1].x), min(abs(vy[i].y - vy[i + 1].y), abs(vy[i].z - vy[i + 1].z)));
        edges.push_back(e2);

        edge e3;
        e3.s = vz[i].idx;
        e3.e = vz[i + 1].idx;
        e3.cost = min(abs(vz[i].x - vz[i + 1].x), min(abs(vz[i].y - vz[i + 1].y), abs(vz[i].z - vz[i + 1].z)));
        edges.push_back(e3);
    }
    sort(edges.begin(), edges.end());
    
    long long sum = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (mst.unite(edges[i].s, edges[i].e)) {
            sum += edges[i].cost;
        }
    }

    cout << sum;

    return 0;
}