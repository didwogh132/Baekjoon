#include <iostream>
#include <vector>

using namespace std;

long long solve(int n, vector<long long>& memo) {
    if (memo[n] != -1) return memo[n];
    if (n == 0) return memo[n] = 1;

    long long sum = 0;
    for (int i = 0; i <= n - 1; i++) {
        long long left = solve(i, memo);
        long long right = solve(n - 1 - i, memo);
        sum += left * right;
    }
    memo[n] = sum;
    return memo[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    vector<long long> memo(n + 1, -1);

    cout << solve(n, memo);
    return 0;
}