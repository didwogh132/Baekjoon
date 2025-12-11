#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr;
    vector<int> ans_arr;

    int max = 0;

    for (int i = 1; i <= n; i++) {
        int next = i;
        int cnt = 2;
        arr.push_back(n);
        arr.push_back(i);
        while (next >= 0) {
            next = arr[cnt - 2] - arr[cnt - 1];
            if (next >= 0) {
                arr.push_back(next);
                cnt++;
            }
        }

        if (cnt > max) {
            max = cnt;
            swap(ans_arr, arr);
        }
        arr.clear();
    }

    cout << max << "\n";

    for (int i = 0; i < ans_arr.size(); i++) {
        cout << ans_arr[i] << " ";
    }

    return 0;
}