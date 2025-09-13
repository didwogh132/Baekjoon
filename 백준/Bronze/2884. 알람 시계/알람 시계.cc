#include <iostream>

using namespace std;


int main() {
    int h, m;
    cin >> h >> m;

    if (m < 45) {
        h = (h + 23) % 24;
        m = m + 15;
    }
    else {
        m = m - 45;
    }

    cout << h << " " << m;
    return 0;
}