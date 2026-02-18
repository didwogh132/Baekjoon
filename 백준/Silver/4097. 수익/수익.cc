#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        long long ans, now;
        long long x;
        cin >> x;
        now = ans = x;

        for (int i = 1; i < n; i++) {
            cin >> x;
            now = max(x, now + x);
            ans = max(ans, now);
        }

        cout << ans << "\n";
    }

    return 0;
}