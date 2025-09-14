#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[101];

    for (int i = 0; i < n; i++) cin >> arr[i];
    int max = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] > m) continue;
                else {
                    if (arr[i] + arr[j] + arr[k] > max) max = arr[i] + arr[j] + arr[k];
                }
            }
        }
    }

    cout << max;

    return 0;
}