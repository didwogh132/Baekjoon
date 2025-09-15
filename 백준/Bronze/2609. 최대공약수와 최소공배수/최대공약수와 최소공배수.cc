#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int max = 0;
    int c, d;
    int ret = (a > b) ? b : a;
    for (int i = 1; i <= ret; i++) {
        if (a % i == 0 && b % i == 0) {
            max = i;
            c = a / i;
            d = b / i;
        }
    }

    cout << max << "\n";
    cout << max * c * d;

    return 0;
}