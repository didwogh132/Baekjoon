#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    long long x;
    long long y;
};

point pivot;

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

bool cmp(const point& a, const point& b) {
    long long c = ccw(pivot, a, b);
    if (c > 0) return true;
    else if (c < 0) return false;
    else {
        long long da = dist2(pivot, a);
        long long db = dist2(pivot, b);
        return da < db;
    }
}

vector<point> grahamScan(vector<point> pts) {
    int n = pts.size();
    if (n <= 1) return pts;

    int p = 0;
    for (int i = 0; i < n; i++) {
        if (pts[i].y < pts[p].y) {
            p = i;
        }
        else if (pts[i].y == pts[p].y && pts[i].x < pts[p].x) {
            p = i;
        }
    }

    point tmp = pts[0];
    pts[0] = pts[p];
    pts[p] = tmp;

    pivot = pts[0];

    if (n >= 2) sort(pts.begin() + 1, pts.end(), cmp);

    if (n == 2) {
        vector<point> hull2;
        hull2.push_back(pts[0]);
        hull2.push_back(pts[1]);
        return hull2;
    }

    vector<point> hull;
    hull.push_back(pts[0]);
    hull.push_back(pts[1]);

    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2) {
            int sz = hull.size();
            point p1 = hull[sz - 2];
            point p2 = hull[sz - 1];
            long long c = ccw(p1, p2, pts[i]);
            if (c > 0) break;
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }

    return hull;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int p;
    cin >> p;

    while (p--) {
        int n;
        cin >> n;
        vector<point> pts;
        pts.resize(n);
        for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
        
        vector<point> hull = grahamScan(pts);
        int h = hull.size();

        int start = 0;
        for (int i = 0; i < h; i++) {
            if (hull[i].y > hull[start].y) {
                start = i;
            }
            else if (hull[i].y == hull[start].y && hull[i].x < hull[start].x) {
                start = i;
            }
        }

        cout << h << "\n";

        for (int k = 0; k < h; k++) {
            int idx = (start - k + h) % h;
            cout << hull[idx].x << " " << hull[idx].y << "\n";
        }

    }

    return 0;
}