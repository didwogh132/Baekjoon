#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n+1);
    vector<int> p(n+1);
    vector<vector<int>> dp(n+1, vector<int>(101,0));

    for(int i =1; i <= n; i++) cin >> h[i];
    for(int i =1; i <= n; i++) cin >> p[i];

    
    for(int i =1; i <= n; i++) {
        for(int j = 0; j <= 99; j++) {
            dp[i][j] = dp[i-1][j];

            if(j >= h[i]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-h[i]] + p[i]);
            }
        }
    }

    cout << dp[n][99];
    return 0;
}