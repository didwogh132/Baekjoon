#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> ring(n + 1);
    vector<int> weight(n + 1);
    vector<int> dp(m+1, 0);

    for(int i =1; i <= n; i++) cin >> weight[i] >> ring[i];

    for(int i = 1; i <= n; i++) {
        for (int j = m; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + ring[i]);
        }
    }

    cout << dp[m];
    return 0;
}