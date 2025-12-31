#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int e, f, n;
        cin >> e >> f;
        int target = f - e;
        cin >> n;
        vector<int> dp;
        vector<int> p;
        vector<int> w;
        dp.resize(target + 1, INT_MAX);
        p.resize(n + 1);
        w.resize(n + 1);

        for (int i = 1; i <= n; i++) cin >> p[i] >> w[i];

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = w[i]; j <= target; j++) {
                if (dp[j - w[i]] == INT_MAX) continue;

                dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
            }
        }
        
        if (dp[target] == INT_MAX) {
            cout << "This is impossible.\n";
        }
        else {
            cout << "The minimum amount of money in the piggy-bank is " << dp[target] << ".\n";
        }
    }
    return 0;
}