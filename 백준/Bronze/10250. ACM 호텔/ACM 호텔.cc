#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int h, w, n;
        cin >> h >> w >> n;

        int y = n % h;
        int x = n / h + 1;

        if (y == 0) {
            y = h;
            x = n / h;
        }

        if (x < 10) {
            cout << y << "0" << x << "\n";
        }
        else {
            cout << y << x << "\n";
        }
    }

    return 0;
}