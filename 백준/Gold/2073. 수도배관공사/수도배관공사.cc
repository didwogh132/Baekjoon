#include <iostream>
#include <memory.h>

using namespace std;

long long dp[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int d, p;
    long long L[351];
    long long C[351];

    cin >> d >> p;
    for (int i = 1; i <= p; i++) {
        cin >> L[i] >> C[i];
    }

    memset(dp, 0, sizeof(dp));
    dp[0] = 2e9;

    for (int i = 1; i <= p; i++) {
        for (int j = d; j >= L[i]; j--) {
            if (dp[j - L[i]] == 0) continue;

            int cand = (dp[j - L[i]] < C[i]) ? dp[j - L[i]] : C[i];
            if (cand > dp[j]) {
                dp[j] = cand;
            }
        }
    }

    cout << dp[d];

    return 0;
}