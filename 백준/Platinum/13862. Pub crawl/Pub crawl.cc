#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    long long x;
    long long y;
    int idx;
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
        p[i].idx = i + 1;
    }

    if (n == 1) {
        cout << "1" << "\n" << "1";
        return 0;
    }
    else if (n == 2) {
        cout << "2" << "\n" << p[0].idx << " " << p[1].idx;
        return 0;
    }


    sort(p.begin() , p.end(), cmp);

    vector<char> in;
    in.assign(n + 1, 0);
    vector<point> st;
    st.reserve(n);

    while (st.size() < n) {
        for (int i = 0; i < n; i++) {
            int id = p[i].idx;
            if (in[id]) continue;

            while (st.size() >= 2) {
                int sz = st.size();
                if (ccw(st[sz - 2], st[sz - 1], p[i]) > 0) break;
                in[st[sz - 1].idx] = 0;
                st.pop_back();
            }
            st.push_back(p[i]);
            in[id] = 1;
        }
        int base = st.size();

        for (int i = n - 1; i >= 0; i--) {
            int id = p[i].idx;
            if (in[id]) continue;

            while (st.size() > base) {
                int sz = st.size();
                if (ccw(st[sz - 2], st[sz - 1], p[i]) > 0) break;
                in[st[sz - 1].idx] = 0;
                st.pop_back();
            }
            st.push_back(p[i]);
            in[id] = 1;
        }
    }

    cout << st.size() << "\n";

    for (int i = 0; i < n; i++) {
        cout << st[i].idx << " ";
    }
    return 0;
}