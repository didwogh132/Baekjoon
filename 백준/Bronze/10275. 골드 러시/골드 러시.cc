#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        long long ret = (a < b) ? a : b;

        long long tz = 0;

        while ((ret & 1) == 0) {
            ret >>= 1;
            tz++;
        }
        cout << (n - tz) << "\n";
    }
    return 0;
}