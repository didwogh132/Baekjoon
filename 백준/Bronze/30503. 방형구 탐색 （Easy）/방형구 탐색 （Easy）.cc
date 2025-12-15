#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n;

    int arr[1001];

    for (int i = 1; i <= n; i++) cin >> arr[i];

    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, l, r, k;
        cin >> a;
        if (a == 1) {
            cin >> l >> r >> k;
            int ans = 0;
            for (int j = l; j <= r; j++ ) {
                if (arr[j] == k) ans++;
            }
            cout << ans << "\n";
        }
        else if (a == 2) {
            cin >> l >> r;
            for (int j = l; j <= r; j++) arr[j] = 0;
        }
    }

    return 0;
}