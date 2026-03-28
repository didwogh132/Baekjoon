#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, c;
    cin >> n >> c;

    vector<int> coin;
    vector<int> dp;
    coin.resize(c);
    dp.resize(n +1, 0);

    for(int i = c-1; i >= 0; i--) {
        cin >> coin[i];
    }

    dp[0] = 1;
    
    for(int i = 0; i < c; i++) {

        for(int j = coin[i]; j <= n; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[n];
    return 0;
}