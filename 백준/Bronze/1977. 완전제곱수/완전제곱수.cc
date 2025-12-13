#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a;

    for (int i = 1; i <= 100; i++) {
        a.push_back(i * i);
    }
    int m, n;
    cin >> m >> n;

    int ans = 0;
    bool flag = false;
    int num = 0;
    for (int i = 0; i < a.size(); i++) {
        if (!flag && a[i] >= m && a[i] <= n) {
            flag = true;
            ans += a[i];
            num = a[i];
        }
        else if (flag && a[i] >= m && a[i] <= n) {
            ans += a[i];
        }
    }

    if (ans == 0) {
        cout << -1;
    }
    else {
        cout << ans << "\n" << num;
    }

    return 0;
}