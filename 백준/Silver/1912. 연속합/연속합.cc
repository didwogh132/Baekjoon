#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    long long now, ans;
    long long x;
    cin >> x;
    now = ans = x;

    for (int i = 1; i < n; i++) {
        cin >> x;
        now = max(x, x + now);
        ans = max(ans, now);
    }

    cout << ans;

    return 0;
}