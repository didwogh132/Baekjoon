#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    long long x;
    long long y;
};

long long ccw(const point& a, const point& b, const point& c) {
    long long x1 = b.x - a.x;
    long long y1 = b.y - a.y;
    long long x2 = c.x - a.x;
    long long y2 = c.y - a.y;
    return x1 * y2 - y1 * x2;
}

bool cmp(const point& a, const point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
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
        cout << n << "\n";
        return 0;
    }

    sort(p.begin(), p.end(), cmp);

    vector<point> hull;
    hull.reserve(2 * n);

    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2) {
            int sz = hull.size();
            point a = hull[sz - 2];
            point b = hull[sz - 1];
            point c = p[i];
            long long dir = ccw(a, b, c);
            if (dir <= 0) {
                hull.pop_back();
            }
            else {
                break;
            }
        }
        hull.push_back(p[i]);
    }

    int lowersize = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() > lowersize) {
            int sz = hull.size();
            point a = hull[sz - 2];
            point b = hull[sz - 1];
            point c = p[i];
            long long dir = ccw(a, b, c);
            if (dir <= 0) {
                hull.pop_back();
            }
            else {
                break;
            }
        }
        hull.push_back(p[i]);
    }
    hull.pop_back();

    cout << hull.size() << "\n";

    return 0;
}