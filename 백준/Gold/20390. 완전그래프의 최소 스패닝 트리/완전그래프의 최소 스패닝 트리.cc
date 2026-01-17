#include <iostream>
#include <vector>
#include <climits>

using namespace std;

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

static void print_int128(__int128 x) {
    if (x == 0) { cout << 0; return; }
    if (x < 0) { cout << "-"; x = -x; }
    char buf[64];
    int idx = 0;
    while (x > 0) {
        int digit = (int)(x % 10);
        buf[idx++] = (char)('0' + digit);
        x /= 10;
    }
    for (int i = idx - 1; i >= 0; i--) cout << buf[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long a, b, c, d;
    vector<long long> y;
    cin >> n;

    cin >> a >> b >> c >> d;

    algo::ds::MST mst(n);
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        y.push_back(num);
    }

    vector<unsigned long long> dist(n, ULLONG_MAX);
    vector<char> used(n, 0);
    dist[0] = 0;

    __int128 sum = 0;

    for (int it = 0; it < n; it++) {
        int v = -1;
        unsigned long long best = ULLONG_MAX;

        for (int i = 0; i < n; i++) {
            if (!used[i] && dist[i] < best) {
                best = dist[i];
                v = i;
            }
        }
        used[v] = 1;

        sum += (__int128)best;

        for (int to = 0; to < n; to++) {
            if (used[to]) continue;

            int i = v;
            int j = to;
            if (i > j) {
                int temp = i;
                i = j;
                j = temp;
            }
            __int128 t = (__int128)y[i] * (__int128)a + (__int128)y[j] * (__int128)b;
            long long base = (long long)(t % (__int128)c);
            unsigned long long cost = (unsigned long long)(base ^ d);

            if (cost < dist[to]) dist[to] = cost;
        }
    }
    print_int128(sum);

    return 0;
}