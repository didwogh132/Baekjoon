#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    long long x;
    long long y;
    int idx;
};
point p0;
long long ccw(const point& a, const point& b, const point& c) {
    long long x1 = b.x - a.x;
    long long y1 = b.y - a.y;
    long long x2 = c.x - a.x;
    long long y2 = c.y - a.y;
    return x1 * y2 - y1 * x2;
}
long long dist2(const point& a, const point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}
bool cmp(const point& a, const point& b) {
    long long dir = ccw(p0, a, b);
    if (dir < 0) return true;
    if (dir > 0) return false;

    long long da = dist2(p0, a);
    long long db = dist2(p0, b);
    return da < db;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<point> p;
        p.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
            p[i].idx = i;
        }

        if (n <= 2) {
            for (int i = 0; i < n; i++) {
                cout << p[i].idx << " ";
            }
            cout << "\n";
            continue;
        }
        int pivot = 0;

        for (int i = 0; i < n; i++) {
            if (p[i].y < p[pivot].y) {
                pivot = i;
            }
            else if (p[i].y == p[pivot].y && p[i].x < p[pivot].x) {
                pivot = i;
            }
        }

        point tmp = p[0];
        p[0] = p[pivot];
        p[pivot] = tmp;
        p0 = p[0];

        sort(p.begin() + 1, p.end(), cmp);

        int last = n - 1;

        while (last > 1) {
            long long dir = ccw(p0, p[last - 1], p[last]);
            if (dir == 0) {
                last--;
            }
            else {
                break;
            }
        }

        reverse(p.begin() + last, p.end());

        for (int i = 0; i < n; i++) {
            cout << p[i].idx << " ";
        }
        cout << "\n";
    }

    return 0;
}