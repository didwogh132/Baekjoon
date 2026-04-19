#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> arr;
    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int num = 0;

    for (int i = 0; i < n; i++) {
        if (num < arr[i]) {
            num = arr[i] + 1;
        }
        else {
            num++;
        }
    }

    cout << num;
    return 0;
}