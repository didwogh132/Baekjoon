#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> arr;
    arr.resize(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = INT_MAX;

    for (int i = 0; i < n - 1; i++) {
        if (ans > arr[i] * x + arr[i + 1] * x) {
            ans = arr[i] * x + arr[i + 1] * x;
        }
    }

    cout << ans;
    return 0;
}