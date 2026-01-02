#include <iostream>
#include <string>

using namespace std;

int dp[4005][4005];

int main() {
    string a, b;
    cin >> a >> b;

    int ans = 0;
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > ans) ans = dp[i][j];
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    cout << ans;
    return 0;
}