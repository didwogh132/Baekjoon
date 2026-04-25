#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, n;
    cin >> p >> n;

    vector<int> jewel(n);

    for (int i = 0; i < n; i++) cin >> jewel[i];

    sort(jewel.begin(), jewel.end());

    int num = 200 - p;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (num > 0) {
            ans++;
            num -= jewel[i];
        }
        else break;
    }

    cout << ans;
    return 0;
}