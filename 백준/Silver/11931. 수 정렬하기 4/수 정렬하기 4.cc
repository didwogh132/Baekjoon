#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000010];

int main() {
    int n;
    cin >> n;
    

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<>());

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}