#include <iostream>

using namespace std;

int n;

int divid(int n, int y, int x) {
    if (n == 0) return 0;

    int half = 1 << (n - 1);
    int offset = 0;

    if (y < half && x < half) {
        offset = 0;
        return offset * half * half + divid(n - 1, y, x);
    }
    else if (y < half && x >= half) {
        offset = 1;
        return offset * half * half + divid(n - 1, y, x - half);
    }
    else if (y >= half && x < half) {
        offset = 2;
        return offset * half * half + divid(n - 1, y - half, x);
    }
    else {
        offset = 3;
        return offset * half * half + divid(n - 1, y - half, x - half);
    }

}

int main() {
    cin >> n;

    int y, x;
    cin >> y >> x;

    cout << divid(n, y, x);

    return 0;
}