#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    a = abs(a);
    b = abs(b);
    if (a + b <= c) {
        if ((a + b) % 2 == 0 && c % 2 == 0) {
            cout << "YES";
        }
        else if ((a + b) % 2 == 1 && c % 2 == 1) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    else {
        cout << "NO";
    }
    return 0;
}