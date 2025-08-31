#include <iostream>

using namespace std;

int n;
int arr[1010];
int dp[1010];

int main() {
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    int answer = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        if (answer < dp[i]) answer = dp[i];
    }

    cout << answer;

    return 0;
}