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
point pivot;
long long ccw(const point& a, const point& b, const point& c) {
    long long x1 = b.x - a.x;
    long long y1 = b.y - a.y;
    long long x2 = c.x - a.x;
    long long y2 = c.y - a.y;
    return x1 * y2 - y1 * x2;
}

bool cmp(const point& a, const point& b) {
    long long dir = ccw(pivot, a, b);
    if (dir > 0)return true;
    if (dir < 0) return false;
    long long da = dist2(a, pivot);
    long long db = dist2(b, pivot);
    return da < db;
}

bool on_seg(const point& a, const point& b, const point& q) {
    if (ccw(a, b, q) != 0) return false;

    long long minx = (a.x < b.x) ? a.x : b.x;
    long long maxx = (a.x > b.x) ? a.x : b.x;
    long long miny = (a.y < b.y) ? a.y : b.y;
    long long maxy = (a.y > b.y) ? a.y : b.y;

    if (q.x < minx || q.x > maxx) return false;
    if (q.y < miny || q.y > maxy) return false;
    return true;
}

bool inside_strict(const vector<point>& hull, const point& q) {
    int m = hull.size();
    if (m < 3) return false;

    int i = 0;
    while (i < m) {
        int j = i + 1;
        if (j == m) j = 0;
        if (ccw(hull[i], hull[j], q) <= 0) return false;
        i++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    long long px, py;
    vector<point> p;
    cin >> n >> px >> py;
    
    p.resize(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    point prison = { px, py };

    int ans = 0;

    while (p.size() >= 3) {
        int szn = p.size();

        int idx = 0;
        int k = 1;
        while (k < szn) {
            if (p[k].y < p[idx].y) idx = k;
            else if (p[k].y == p[idx].y && p[k].x < p[idx].x) idx = k;
            k++;
        }

        point temp = p[0];
        pivot = p[idx];
        p[0] = pivot;
        p[idx] = temp;

        sort(p.begin() + 1, p.end(), cmp);

        vector<point> hull;
        hull.push_back(p[0]);
        hull.push_back(p[1]);

        for (int i = 2; i < szn; i++) {
            while (hull.size() >= 2) {
                int sz = hull.size();
                point p1 = hull[sz - 2];
                point p2 = hull[sz - 1];
                long long dir = ccw(p1, p2, p[i]);
                if (dir <= 0) {
                    hull.pop_back();
                }
                else {
                    break;
                }
            }
            hull.push_back(p[i]);
        }

        if (hull.size() < 3) break;
        if (!inside_strict(hull, prison)) break;

        ans++;

        vector<point> nextp;
        int m = hull.size();

        int a = 0;
        while (a < szn) {
            bool boundary = false;

            int e = 0;
            while (e < m) {
                int f = e + 1;
                if (f == m) f = 0;

                if (on_seg(hull[e], hull[f], p[a])) {
                    boundary = true;
                    break;
                }
                e++;
            }
            
            if (!boundary) nextp.push_back(p[a]);
            a++;
        }

        p = nextp;
    }

    cout << ans;


    return 0;
}