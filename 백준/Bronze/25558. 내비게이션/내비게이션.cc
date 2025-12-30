#include <iostream>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    long long sy, sx, ey, ex;
    cin >> n >> sx >> sy >> ex >> ey;
    
    long long prevx = sx;
    long long prevy = sy;
    int min_idx = 0;
    long long ans_min = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        long long dist = 0;
        for (int j = 0; j < m; j++) {
            long long x, y;
            cin >> x >> y;
            dist += abs(prevx - x) + abs(prevy - y);
            prevx = x;
            prevy = y;
        }

        dist += abs(prevx - ex) + abs(prevy - ey);
        if (dist < ans_min) {
            min_idx = i;
            ans_min = dist;
        }
        prevx = sx;
        prevy = sy;
    }
    cout << min_idx;

    return 0;
}