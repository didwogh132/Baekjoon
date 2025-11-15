#include <iostream>

using namespace std;

long long n, b ,c;
long long arr[1000010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> b >> c;

    for (int i = 0; i < n; i++) cin >> arr[i];

    long long cost = 0;

    if (c >= b) {
        for (int i = 0; i < n; i++) {
            cost += arr[i] * b;
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (arr[i + 1] > arr[i + 2]) {
                int diff = arr[i + 1] - arr[i + 2];
                int two = (arr[i] > diff) ? diff : arr[i];
                arr[i] -= two;
                arr[i + 1] -= two;
                cost += two * (b + c);
            }

            int three = (arr[i] > arr[i + 1]) ? arr[i + 1] : arr[i];

            arr[i + 2] -= three;
            arr[i + 1] -= three;
            arr[i] -= three;
            cost += three * (b + 2 * c);

            if (arr[i] > 0) {
                cost += arr[i] * b;
                arr[i] = 0;
            }
        }
    }

    cout << cost;

    return 0;
}