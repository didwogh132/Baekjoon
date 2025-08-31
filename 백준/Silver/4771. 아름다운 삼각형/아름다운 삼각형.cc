#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

#define M_PI 3.141592

using namespace std;

struct Point {
    double x, y;
    Point operator-(Point const& o) const {
        return { x - o.x, y - o.y };
    }
};

double cross(Point const& p1, Point const& p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

double dist2(Point const& a, Point const& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double eps = 1e-8;

    while (true) {
        string s;
        cin >> s;
        if (s == "-1") break;

        Point p[3];

        p[0].x = stod(s);
        cin >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y;

        if (fabs(cross(p[1] - p[0], p[2] - p[0])) < eps) {
            cout << "Not a Triangle\n";
            continue;
        }

        double len[3] = {
            sqrt(dist2(p[0], p[1])),
            sqrt(dist2(p[1], p[2])),
            sqrt(dist2(p[2], p[0]))
        };

        sort(len, len + 3);

        if (fabs(len[0] - len[2]) <= 0.01) {
            cout << "Equilateral ";
        }
        else if (fabs(len[0] - len[1]) <= 0.01 || fabs(len[1] - len[2]) <= 0.01) {
            cout << "Isosceles ";
        }
        else {
            cout << "Scalene ";
        }

        double c = len[2], a = len[0], b = len[1];
        double cosC = (a * a + b * b - c * c) / (2 * a * b);
        cosC = min(1.0, max(-1.0, cosC));
        double angleC = acos(cosC) * 180.0 / M_PI;

        if (fabs(angleC - 90.0) <= 0.01) {
            cout << "Right\n";
        }
        else if (angleC > 90.0 + 0.01) {
            cout << "Obtuse\n";
        }
        else {
            cout << "Acute\n";
        }
    }
    return 0;
}