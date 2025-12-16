#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = a * b;
    int bs[3];

    for (int i = 0; i < 3; i++) {
        bs[i] = b % 10;
        b /= 10;
    }

    for (int i = 0; i < 3; i++) {
        cout << a * bs[i] << "\n";
    }
    cout << ans;
    return 0;
}