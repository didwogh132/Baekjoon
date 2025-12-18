#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

struct point {
    long long x;
    long long y;
};

long long dist2(const point& a, const point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}
long long ccw(const point& a, const point& b, const point& c) {
    long long x1 = b.x - a.x;
    long long y1 = b.y - a.y;
    long long x2 = c.x - a.x;
    long long y2 = c.y - a.y;
    return x1 * y2 - y1 * x2;
}
point pivot;
bool cmp(const point& a, const point& b) {
    long long dir = ccw(pivot, a, b);
    if (dir < 0) return false;
    if (dir > 0) return true;

    long long da = dist2(pivot, a);
    long long db = dist2(pivot, b);
    return da < db;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<point> p;
    int n;
    cin >> n;

    p.resize(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    pivot = p[0];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].y < pivot.y) {
            pivot = p[i];
            idx = i;
        }
        else if (p[i].y == pivot.y && p[i].x < pivot.x) {
            pivot = p[i];
            idx = i;
        }
    }
    point temp = p[0];
    p[0] = pivot;
    p[idx] = temp;

    sort(p.begin() + 1, p.end(), cmp);

    vector<point> hull;
    hull.push_back(p[0]);
    hull.push_back(p[1]);

    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2) {
            int sz = hull.size();
            point p1 = hull[sz - 2];
            point p2 = hull[sz - 1];
            long long dir = ccw(p1, p2, p[i]);
            if (dir <= 0) hull.pop_back();
            else {
                break;
            }
        }
        hull.push_back(p[i]);
    }

    long double ans = 0;
    for (int i = 0; i < hull.size(); i++) {
        int i2 = (i + 1) % hull.size();
        ans += sqrt((hull[i].x - hull[i2].x) * (hull[i].x - hull[i2].x) + (hull[i].y - hull[i2].y) * (hull[i].y - hull[i2].y));
    }

    cout << fixed << setprecision(2) << ans;

    return 0;
}