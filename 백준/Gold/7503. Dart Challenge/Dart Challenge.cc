#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n, dart;

        bitset<15005> dp;
        dp.set(0);

        cin >> n >> dart;

        vector<int> score(n);

        for (int i = 0; i < n; i++) cin >> score[i];

        sort(score.begin(), score.end());

        for (int i = 0; i < dart; i++) {
            bitset<15005> ndp = dp;
            for (int j = 0; j < n - 1; j++) {
                ndp |= (dp << score[j]);
                ndp |= (dp << score[j] * 2);
                ndp |= (dp << score[j] * 3);
            }
            ndp |= (dp << score.back());
            ndp |= (dp << score.back() * 2);
            dp = ndp;
        }

        cout << "Scenario #" << tc << ":" << "\n" << dp.count() << "\n\n" ;
    }

    return 0;
}