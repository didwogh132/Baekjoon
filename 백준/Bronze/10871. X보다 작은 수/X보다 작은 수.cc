#include <iostream>

using namespace std;


int main() {
    int n, x;
    int arr[10001] = { 0, };
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < x) cout << arr[i] << " ";
    }

    return 0;
}