#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    if (a >= b) {
        for (int i = 1; i <= b; i++) {
            if (a % i == 0 && b % i == 0) {
                cout << i << " " << a / i << " " << b / i << "\n";
            }
        }
    }
    else {
        for (int i = 1; i <= a; i++) {
            if (a % i == 0 && b % i == 0) {
                cout << i << " " << a / i << " " << b / i << "\n";
            }
        }
    }

    return 0;
}