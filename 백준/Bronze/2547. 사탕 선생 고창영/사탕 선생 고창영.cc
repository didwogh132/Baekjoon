#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long num;
            cin >> num;
            sum += num;
            sum %= n;
        }

        if (sum % n == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}