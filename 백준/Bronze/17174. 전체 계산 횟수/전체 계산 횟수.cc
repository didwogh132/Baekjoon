#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int ans = 0;
    cin >> n >> m;

    ans += n;
    while (n >= m) {
        ans += n / m;
        n /= m;
    }

    cout << ans;

    return 0;
}