#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long ans_left = 0, ans_mid = 0, ans_right = 0;
    long long ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            long long ret = 0;
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }
            ret = arr[i] + arr[left] + arr[right];
            if (llabs(ret) <llabs(ans)) {
                ans = ret;
                ans_left = arr[left];
                ans_mid = arr[i];
                ans_right = arr[right];
                if (ans == 0) break;
            }
            if (ret < 0) left++;
            else right--;
        }
    }

    if (ans_left > ans_right) swap(ans_left, ans_right);
    if (ans_mid > ans_right) swap(ans_mid, ans_right);
    if (ans_left > ans_mid) swap(ans_left, ans_mid);

    cout << ans_left << " " << ans_mid << " " << ans_right;
    return 0;
}