#include <iostream>

using namespace std;

struct point {
    int x;
    int y;
};

int ccw(point a, point b, point c) {
    int x1 = b.x - a.x;
    int y1 = b.y - a.y;
    int x2 = c.x - a.x;
    int y2 = c.y - a.y;
    return x1 * y2 - y1 * x2;
}

int main() {
    point a, b, c;

    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    int dir = ccw(a, b, c);

    if (dir > 0) cout << 1;
    else if (dir == 0) cout << 0;
    else cout << -1;
    

    return 0;
}