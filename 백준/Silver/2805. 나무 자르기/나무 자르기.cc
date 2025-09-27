#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int low = 0;
    int high = arr[n - 1];
    long long sum = 0;
    int ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        sum = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] <= mid) continue;
            else {
                sum += (arr[i] - mid);
            }
        }

        if (sum == m) {
            ans = mid;
            break;
        }
        else if (sum > m) {
            low = mid + 1;
            ans = mid;
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans;

    return 0;
}