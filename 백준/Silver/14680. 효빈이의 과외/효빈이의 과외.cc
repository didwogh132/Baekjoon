#include <iostream>
#include <memory.h>

#define MOD 1000000007

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int x, y;
    long long a[51][51];
    long long b[51][51];
    long long next[51][51];
    memset(next, 0, sizeof(next));

    cin >> x >> y;
    for (int j = 0; j < x; j++) {
        for (int k = 0; k < y; k++) {
            cin >> a[j][k];
        }
    }

    for (int i = 1; i < n; i++) {
        int r, c;
        cin >> r >> c;
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                cin >> b[j][k];
            }
        }

        if (y != r) {
            cout << -1;
            return 0;
        }

        for (int j = 0; j < x; j++) {
            for (int k = 0; k < c; k++) {
                long long sum = 0;
                for (int l = 0; l < y; l++) {
                    long long temp = (a[j][l] * b[l][k]) % MOD;
                    sum += temp;
                    if (sum >= MOD) sum %= MOD;
                }
                next[j][k] = sum;
            }
        }

        for (int k = 0; k < x; k++) {
            for (int j = 0; j < c; j++) {
                a[k][j] = next[k][j];
            }
        }
        y = c;
    }

    long long ans = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ans += a[i][j];
            if (ans >= MOD) ans %= MOD;
        }
    }

    cout << (ans % MOD);

    return 0;
}