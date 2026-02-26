#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

struct point;
extern point pivot;
long long dist2(const point& a, const point& b);
long long ccw(const point& a, const point& b, const point& c);

struct point {
    long long x, y;

    bool operator==(const point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator<(const point& other) const {
        long long dir = ccw(pivot, *this, other);
        if (dir > 0) return true;
        if (dir < 0) return false;

        long long da = dist2(pivot, *this);
        long long db = dist2(pivot, other);
        return da < db;
    }
};

point pivot;

long long dist2(const point& a, const point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

long long ccw(const point& a, const point& b, const point& c) {
    long long x1 = a.x - b.x;
    long long y1 = a.y - b.y;
    long long x2 = a.x - c.x;
    long long y2 = a.y - c.y;
    return x1 * y2 - y1 * x2;
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
        }

        if (n == 1) {
            cout << p[0].x << " " << p[0].y << " " << p[0].x << " " << p[0].y << "\n";
            continue;
        }

        pivot = p[0];
        int idx = 0;

        for (int i = 1; i < n; i++) {
            if (p[i].y < pivot.y || (p[i].y == pivot.y && p[i].x < pivot.x)) {
                pivot = p[i];
                idx = i;
            }
        }

        point temp = p[0];
        p[0] = pivot;
        p[idx] = temp;

        sort(p.begin() + 1, p.end());

        vector<point> sorted;
        sorted.reserve(n);
        sorted.push_back(p[0]);
        for (int i = 1; i < n; i++) {
            if (!(p[i] == sorted[(int)sorted.size() - 1])) {
                sorted.push_back(p[i]);
            }
        }

        if (sorted.size() == 1) {
            cout << sorted[0].x << ' ' << sorted[0].y << ' ' << sorted[0].x << ' ' << sorted[0].y << '\n';
            continue;
        }

        if (sorted.size() == 2) {
            cout << sorted[0].x << ' ' << sorted[0].y << ' ' << sorted[1].x << ' ' << sorted[1].y << '\n';
            continue;
        }

        vector<point> hull;
        hull.reserve(sorted.size());
        hull.push_back(sorted[0]);
        hull.push_back(sorted[1]);

        for (int i = 2; i < sorted.size(); i++) {
            while (hull.size() >= 2) {
                int sz = hull.size();
                point p1 = hull[sz - 2];
                point p2 = hull[sz - 1];
                long long dir = ccw(p1, p2, sorted[i]);
                if (dir <= 0) hull.pop_back();
                else break;
            }
            hull.push_back(sorted[i]);
        }

        if (hull.size() == 2) {
            cout << hull[0].x << ' ' << hull[0].y << ' ' << hull[1].x << ' ' << hull[1].y << '\n';
            continue;
        }

        int m = hull.size();
        int j = 1;

        long long best = dist2(hull[0], hull[1]);
        point ansA = hull[0];
        point ansB = hull[1];

        for (int i = 0; i < m; i++) {
            int ni = (i + 1) % m;

            while (true) {
                int nj = (j + 1) % m;

                long long cur = llabs(ccw(hull[i], hull[ni], hull[j]));
                long long nxt = llabs(ccw(hull[i], hull[ni], hull[nj]));

                if (nxt > cur) j = nj;
                else break;
            }

            long long d1 = dist2(hull[i], hull[j]);
            if (d1 > best) {
                best = d1;
                ansA = hull[i];
                ansB = hull[j];
            }

            long long d2 = dist2(hull[ni], hull[j]);
            if (d2 > best) {
                best = d2;
                ansA = hull[ni];
                ansB = hull[j];
            }
        }
        cout << ansA.x << ' ' << ansA.y << ' ' << ansB.x << ' ' << ansB.y << '\n';

    }
    return 0;
}