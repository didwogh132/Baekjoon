#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int x, now, ans;
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