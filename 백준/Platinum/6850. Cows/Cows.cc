#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    int x;
    int y;
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
    cin >> n;

    vector<point> p;
    p.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    if (n <= 2) {
        cout << 0;
        return 0;
    }

    int p0 = 0;

    for (int i = 0; i < n; i++) {
        if (p[i].y < p[p0].y) {
            p0 = i;
        }
        else if (p[i].y == p[p0].y && p[i].x < p[p0].x) {
            p0 = i;
        }
    }

    point temp = p[0];
    p[0] = p[p0];
    p[p0] = temp;
    pivot = p[0];

    sort(p.begin() + 1, p.end(), cmp);

    vector<point> hull;
    hull.push_back(p[0]);
    hull.push_back(p[1]);

    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2) {
            int sz = hull.size();
            point a = hull[sz - 2];
            point b = hull[sz - 1];
            point c = p[i];

            if (ccw(a, b, c) <= 0) {
                hull.pop_back();
            }
            else {
                break;
            }
        }
        hull.push_back(p[i]);
    }

    long long area = 0;
    
    for (int i = 0; i < hull.size(); i++) {
        int j = (i + 1) % hull.size();
        area += hull[i].x * hull[j].y - hull[i].y * hull[j].x;
    }

    cout << area / 100;

    return 0;
}