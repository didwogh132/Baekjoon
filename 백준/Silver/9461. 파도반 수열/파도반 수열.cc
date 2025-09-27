#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;


    long long p[101];
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    p[5] = 2;

    for (int i = 6; i <= 100; i++) {
        p[i] = p[i - 1] + p[i - 5];
    }

    for (int tc = 1; tc <= t; tc++) {
        int num;
        cin >> num;
        cout << p[num] << "\n";
    }

    return 0;
}