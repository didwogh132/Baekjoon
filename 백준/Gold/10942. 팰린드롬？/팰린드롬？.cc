#include <iostream>
#include <memory.h>

using namespace std;

bool dp[2001][2001];
int arr[2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    memset(dp, false, sizeof(dp));

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) dp[i][i] = true;

    for (int len = 2; len <= n; len++) {
        for (int s = 1; s + len - 1 <= n; s++) {
            int e = s + len - 1;

            if (arr[s] != arr[e]) {
                dp[s][e] = false;
                continue;
            }
            if (len == 2) {
                dp[s][e] = true;
            }
            else {
                dp[s][e] = dp[s + 1][e - 1];
            }
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (dp[a][b]) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }

    return 0;
}