#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[31];

    arr[0] = 1;

    for (int i = 1; i <= 30; i++) {
        arr[i] = (1 << i);
    }

    bool flag = false;
    for (int i = 0; i <= 30; i++) {
        if (arr[i] == n) flag = true;
    }

    if (flag) cout << 1;
    else cout << 0;
    return 0;
}