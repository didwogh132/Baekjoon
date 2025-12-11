#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    int arr[250010];
    cin >> n >> x;

    for (int i = 0; i < n; i++) cin >> arr[i];

    int max = 0;
    int cnt = 0;
    int sum = 0;

    for (int i = 0; i < x; i++) {
        sum += arr[i];
    }
    if (sum > 0) {
        max = sum;
        cnt++;
    }
    for (int i = x; i < n; i++) {
        sum += arr[i];
        sum -= arr[i - x];
        if (sum > max) {
            max = sum;
            cnt = 1;
        }
        else if (sum == max) {
            cnt++;
        }
    }
    
    if (max == 0) {
        cout << "SAD";
    }
    else {
        cout << max << "\n" << cnt;
    }

    return 0;
}