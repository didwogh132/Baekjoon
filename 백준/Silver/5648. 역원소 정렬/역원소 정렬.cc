#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr;
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;
        reverse(num.begin(), num.end());
        arr.push_back(stoll(num));
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}