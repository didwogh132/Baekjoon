#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> wine;

    wine.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> wine[i];

    long long prev0 = 0;
    long long prev1 = 0;
    long long prev2 = 0;

    for (int i = 1; i <= n; i++) {
        long long now0 = max(prev0, max(prev1, prev2));
        long long now1 = prev0 + wine[i];
        long long now2 = prev1 + wine[i];

        prev0 = now0;
        prev1 = now1;
        prev2 = now2;
    }

    cout << max(prev0, max(prev1, prev2));
    return 0;
}