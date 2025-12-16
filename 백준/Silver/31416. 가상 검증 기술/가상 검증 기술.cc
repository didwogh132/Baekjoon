#include <iostream>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--) {
        int ta, tb, va, vb;
        cin >> ta >> tb >> va >> vb;

        int ans = INT_MAX;

        for (int i = 0; i <= va; i++) {
            int times = ta * i;
            int timed = tb * vb + ta * (va - i);
            int done = (times > timed) ? times : timed;
            ans = (ans < done) ? ans : done;
        }
        cout << ans << "\n";
    }

    return 0;
}