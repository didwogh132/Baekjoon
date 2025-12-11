#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            cout << 1 << "\n";
            continue;
        }
        else if (a % 10 == 0) {
            cout << 10 << "\n";
        }
        else {
            int next = a;
            for (int i = 1; i < b; i++) {
                next = (a * next) % 10;
            }
            cout << next % 10 << "\n";
        }
    }

    return 0;
}