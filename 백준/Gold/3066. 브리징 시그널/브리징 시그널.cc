#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;
        vector<int> lis;
        arr.resize(n);

        for (int i = 0; i < n; i++) cin >> arr[i];

        for (int i = 0; i < n; i++) {
            if (lis.empty() || lis[lis.size() - 1] < arr[i]) {
                lis.push_back(arr[i]);
            }
            else {
                int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
                lis[idx] = arr[i];
            }
        }

        cout << lis.size() << "\n";
    }

    return 0;
}