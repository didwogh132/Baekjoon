#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << "\n";

        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        vector<int> lis;
        for (int i = 0; i < n; i++) cin >> arr[i];

        for (int i = 0; i < n; i++) {
            int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();

            if (idx == lis.size()) {
                lis.push_back(arr[i]);
            }
            else {
                lis[idx] = arr[i];
            }
        }

        if (k <= lis.size()) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }

    return 0;
}