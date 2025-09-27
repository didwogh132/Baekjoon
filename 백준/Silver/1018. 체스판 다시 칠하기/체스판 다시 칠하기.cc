#include <iostream>
#include <string>

using namespace std;

int main() {
    string arr[52];

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int min = 50;
    int ans = 0;

    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {

            int cnt = 0;
            //i, j에서 W 시작
            for (int y = i; y < i + 8; y++) {
                for (int x = j; x < j + 8; x++) {
                    if ((y + x) % 2 == 0) {
                        if (arr[y][x] == 'W') continue;
                        else cnt++;
                    }
                    else {
                        if (arr[y][x] == 'B') continue;
                        else cnt++;
                    }
                }
            }

            if (cnt < min) min = cnt;

            cnt = 0;
            //i, j에서 B 시작
            for (int y = i; y < i + 8; y++) {
                for (int x = j; x < j + 8; x++) {
                    if ((y + x) % 2 == 0) {
                        if (arr[y][x] == 'B') continue;
                        else cnt++;
                    }
                    else {
                        if (arr[y][x] == 'W') continue;
                        else cnt++;
                    }
                }
            }
            if (cnt < min) min = cnt;
        }
        if (min == 0) break;
    }

    if (min == 50) ans = 0;
    else ans = min;

    cout << ans;

    return 0;
}