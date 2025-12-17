#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;

    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        ans += num;
    }
    string a = (ans < t) ? "Padaeng_i Cry" : "Padaeng_i Happy";
    cout << a;
    return 0;
}