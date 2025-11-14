#include <iostream>

using namespace std;

int n;
int arr[10005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i + 1] > arr[i + 2]) {
            int dist = arr[i + 1] - arr[i + 2];
            int two = (arr[i] > dist) ? dist : arr[i];
            arr[i] -= two;
            arr[i + 1] -= two;
            ans += two * 5;
        }

        int threedist = (arr[i] < arr[i + 1]) ? arr[i] : arr[i + 1];
        
        arr[i + 2] -= threedist;
        arr[i + 1] -= threedist;
        arr[i] -= threedist;
        ans += threedist * 7;

        if (arr[i] > 0) {
            ans += arr[i] * 3;
            arr[i] = 0;
        }
    }

    cout << ans;
    return 0;
}