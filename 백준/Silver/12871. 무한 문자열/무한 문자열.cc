#include <iostream>
#include <string>
#include <numeric>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int lenA = a.size();
    int lenB = b.size();
    int lcmLen = lcm(lenA, lenB);
    string x, y;

    for (int i = 0; i < lcmLen / lenA; i++) {
        x += a;
    }
    for (int i = 0; i < lcmLen / lenB; i++) {
        y += b;
    }
    if (x == y) cout << 1;
    else {
        cout << 0;
    }
    return 0;
}