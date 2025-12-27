#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr;
    arr.resize(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    cout << arr[k - 1];
    return 0;
}