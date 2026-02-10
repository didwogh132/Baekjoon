#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a = 0, b = 0;

    if (n > 1000) {
        b = n % 1000;
        a = 10;
    }
    else if (n > 100 && n < 200) {
        b = n % 10;
        a = n / 10;
    }
    else if (n > 200) {
        b = n % 100;
        a = n / 100;
    }
    else if (n > 10) {
        b = n % 10;
        a = n / 10;
    }

    cout << a + b;
    return 0;
}