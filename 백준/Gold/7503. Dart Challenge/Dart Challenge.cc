#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

bool single[301];
bool dp[51][15001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n, dart;
        int score[101];

        memset(single, false, sizeof(single));
        memset(dp, false, sizeof(dp));

        cin >> n >> dart;

        for (int i = 0; i < n; i++) cin >> score[i];

        sort(score, score + n);

        single[0] = true;
        for (int i = 0; i < n; i++) {
            int v = score[i];
            if (i == n - 1) {
                single[v] = true;
                single[v * 2] = true;
            }
            else {
                single[v] = true;
                single[v * 2] = true;
                single[v * 3] = true;
            }
        }
        int max_single = 0;
        for (int i = 0; i <= 300; i++) {
            if (single[i] && i > max_single) max_single = i;
        }
        int max_total = max_single * dart;

        dp[0][0] = true;

        for (int i = 1; i <= dart; i++) {
            for (int s = 0; s <= max_total; s++) {
                if (!dp[i - 1][s]) continue;

                for (int add = 0; add <= max_single; add++) {
                    if (!single[add]) continue;
                    int ns = s + add;
                    if (ns <= max_total) {
                        dp[i][ns] = true;
                    }
                }
            }
        }
        int ans = 0;
        for (int s = 0; s <= max_total; s++) {
            if (dp[dart][s]) ans++;
        }
        cout << "Scenario #" << tc << ":" << "\n" << ans << "\n" << "\n";
    }

    return 0;
}