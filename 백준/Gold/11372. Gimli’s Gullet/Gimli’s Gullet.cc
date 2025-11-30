#include <iostream>
#include <memory.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, m;

    while (true) {
        cin >> v;
        if (v == 0) break;

        int volume[11];
        int calorie[11];
        int used[11];
        int dp[10001];
        int fromdrink[10001];
        memset(dp, -1, sizeof(dp));
        memset(used, 0, sizeof(used));
        memset(fromdrink, -1, sizeof(fromdrink));

        cin >> m;
        dp[0] = 0;
        for (int i = 1; i <= m; i++) cin >> volume[i] >> calorie[i];

        for (int i = 1; i <= m; i++) {
            for (int j = volume[i]; j <= v; j++) {
                if (dp[j - volume[i]] == -1) continue;
                if (dp[j - volume[i]] + calorie[i] > dp[j]) {
                    dp[j] = dp[j - volume[i]] + calorie[i];
                    fromdrink[j] = i;
                }
            }
        }

        int bestcal = -1;
        int bestvol = 0;

        for (int j = 0; j <= v; j++) {
            if (dp[j] > bestcal) {
                bestcal = dp[j];
                bestvol = j;
            }
        }
        int now = bestvol;
        while (now > 0 && fromdrink[now] != -1) {
            int idx = fromdrink[now];
            used[idx]++;
            now -= volume[idx];
        }

        for (int i = 1; i <= m; i++) {
            cout << used[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}