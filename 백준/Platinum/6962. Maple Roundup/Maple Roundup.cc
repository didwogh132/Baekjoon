#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

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
    if (dir > 0) return true;
    if (dir < 0) return false;
    long long da = dist2(a, pivot);
    long long db = dist2(b, pivot);
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

        for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

        if (n == 1) {
            cout << fixed << setprecision(2) << 0.0 << "\n";
            continue;
        }
        else if (n == 2) {
            long double dx = (long double)p[0].x - (long double)p[1].x;
            long double dy = (long double)p[0].y - (long double)p[1].y;
            long double d = sqrt(dx * dx + dy * dy);
            cout << fixed << setprecision(2) << 2 * d << "\n";
            continue;
        }
        int idx = 0;
        for (int i = 1; i < n; i++) {
            if (p[i].y < p[idx].y) {
                idx = i;
            }
            else if (p[i].y == p[idx].y && p[i].x < p[idx].x) {
                idx = i;
            }
        }
        point temp = p[0];
        pivot = p[idx];
        p[0] = p[idx];
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
                if (dir > 0) break;
            }
            hull.push_back(p[i]);
        }

        long double ans = 0;

        for (int i = 0; i < hull.size(); i++) {
            int j = (i + 1) % hull.size();
            ans += sqrt((hull[i].x - hull[j].x) * (hull[i].x - hull[j].x) + (hull[i].y - hull[j].y) * (hull[i].y - hull[j].y));
        }

        cout << fixed << setprecision(2) << ans << "\n";
    }

    return 0;
}