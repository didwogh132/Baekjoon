#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    int arr[100010];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int left = 0;
    int right = n - 1;
    int ans = 2100000000;
    int sum;
    int ans_left, ans_right;

    while (left < right) {
        sum = arr[left] + arr[right];
        if (abs(sum) < ans) {
            ans = abs(sum);
            ans_left = arr[left];
            ans_right = arr[right];
            if (ans == 0) break;
        }
        if (sum < 0) left++;
        else right--;
    }

    cout << ans_left << " " << ans_right;

    return 0;
}
