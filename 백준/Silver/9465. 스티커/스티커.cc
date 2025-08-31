#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int arr[2][100010];
int dp[2][100010];

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));

        cin >> n;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j< n; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 1; j++) {
                dp[i][j] = arr[i][j];
            }
        }
        dp[0][1] = max(arr[1][0] + arr[0][1], arr[0][1]);
        dp[1][1] = max(arr[0][0] + arr[1][1], arr[0][0]);
        
        for (int j = 2; j < n; j++) {
            for (int i = 0; i < 2; i++) {
                dp[i][j] = max((dp[(i + 1) % 2][j - 1] + arr[i][j]), max((dp[0][j - 2] + arr[i][j]), (dp[1][j - 2] + arr[i][j])));
            }
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }
    return 0;
}