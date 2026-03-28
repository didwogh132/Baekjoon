#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = n / 5;

    if (n % 5 > 0) cnt++;

    cout << cnt;

    return 0;
}