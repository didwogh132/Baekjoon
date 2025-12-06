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
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<point> pts;

    for (int i = 0; i < n; i++) {
        long long x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'Y') {
            pts.push_back({ x, y });
        }
    }
    
    vector<point> lower;
    vector<point> upper;

    sort(pts.begin(), pts.end(), cmp);

    for (int i = 0; i < pts.size(); i++) {
        while (lower.size() >= 2) {
            int s = lower.size();
            point pa = lower[s - 2];
            point pb = lower[s - 1];
            long long dir = ccw(pa, pb, pts[i]);
            if (dir < 0) lower.pop_back();
            else break;
        }
        lower.push_back(pts[i]);
    }

    for (int i = pts.size() - 1; i >= 0; i--) {
        while (upper.size() >= 2) {
            int s = upper.size();
            point pa = upper[s - 2];
            point pb = upper[s - 1];
            long long dir = ccw(pa, pb, pts[i]);
            if (dir < 0) upper.pop_back();
            else break;
        }
        upper.push_back(pts[i]);
    }

    vector<point> hull;

    for (int i = 0; i < lower.size() -1; i++) {
        hull.push_back(lower[i]);
    }
    for (int i = 0; i < upper.size() - 1; i++) {
        hull.push_back(upper[i]);
    }
    cout << hull.size() << "\n";

    for (int i = 0; i < hull.size(); i++) {
        cout << hull[i].x << " " << hull[i].y << "\n";
    }

    return 0;
}