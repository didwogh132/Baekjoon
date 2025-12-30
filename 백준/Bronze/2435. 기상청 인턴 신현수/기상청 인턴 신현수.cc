#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> day;
    vector<int> psum;
    day.resize(n + 1);
    psum.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> day[i];
        psum[i] = psum[i - 1] + day[i];
    }

    int ans = -50000;

    for (int i = k; i <= n; i++) {
        if (ans < psum[i] - psum[i - k]) ans = psum[i] - psum[i - k];
    }
    cout << ans;

    return 0;
}