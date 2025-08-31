#include <iostream>
#include <algorithm>

using namespace std;

int n, s;
int arr1[105];
int arr2[5];
int arr3[5];
int used[105];
int m, k;
int ans;

void func(int num) {
    if (num == m) {
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (arr1[i] < arr1[j]) cnt++;
            }
        }
        if (cnt == s) ans++;
        return;
    }

    for (int i = 0; i < m; i++) {
        if (used[arr2[i]] == 1) continue;
        arr1[arr3[num]] = arr2[i];
        used[arr2[i]] = 1;
        func(num + 1);
        arr1[arr3[num]] = 0;
        used[arr2[i]] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> arr1[i];
        if (arr1[i] != 0) used[arr1[i]] = 1;
        else {
            arr3[k] = i;
            k++;
        }
    }
    if (s > 4950) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (used[i] == 0) {
            arr2[m] = i;
            m++;
        }
    }
    func(0);

    cout << ans;

    return 0;
}