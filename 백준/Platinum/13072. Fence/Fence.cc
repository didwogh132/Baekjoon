#include <iostream>
#include <vector>
#include <algorithm>

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
    long long da = dist2(pivot, a);
    long long db = dist2(pivot, b);
    return da < db;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        vector<point> p;
        p.resize(n);

        for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
        if (n == 1) {
            cout << "0 0\n";
            continue;
        }
        else if (n == 2) {
            long long dx = p[0].x - p[1].x; if (dx < 0) dx = -dx;
            long long dy = p[0].y - p[1].y; if (dy < 0) dy = -dy;
            long long mn = (dx < dy) ? dx : dy;
            long long mx = (dx < dy) ? dy : dx;

            cout << (mx - mn) * 2 << " " << mn * 2 << "\n";
            continue;
        }

        int idx = 0;

        for (int i = 0; i < p.size(); i++) {
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
                if (dir > 0) break;
                else {
                    hull.pop_back();
                }
            }
            hull.push_back(p[i]);
        }

        long long a = 0, b = 0;
        int m = hull.size();

        if (m == 1) {
            a = 0, b = 0;
        }
        else if (m == 2) {
            long long dx = hull[0].x - hull[1].x; if (dx < 0) dx = -dx;
            long long dy = hull[0].y - hull[1].y; if (dy < 0) dy = -dy;
            long long mn = (dx < dy) ? dx : dy;
            long long mx = (dx < dy) ? dy : dx;

            a = (mx - mn) * 2;
            b = mn * 2;
        }
        else {
            int i = 0;
            while (i < m) {
                int j = (i + 1) % m;

                long long dx = hull[i].x - hull[j].x; if (dx < 0) dx = -dx;
                long long dy = hull[i].y - hull[j].y; if (dy < 0) dy = -dy;

                long long mn = (dx < dy) ? dx : dy;
                long long mx = (dx < dy) ? dy : dx;

                a += (mx - mn);
                b += mn;

                i++;
            }
        }

        cout << a << " " << b << "\n";
    }

    return 0;
}