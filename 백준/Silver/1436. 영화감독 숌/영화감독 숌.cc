#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tmp;
    int ncnt = 0;
    int cnt = 0;
    int ans = 0;
    for (int i = 666; i <= 100000000; i++) {
        cnt = 0;
        tmp = i;
        while (tmp != 0) {
            if (tmp % 10 == 6) {
                cnt++;
            }
            else {
                cnt = 0;
            }
            if (cnt == 3) {
                ncnt++;
                cnt = 0;
                if (ncnt == n) {
                    ans = i;
                    break;
                }
                else break;
            }

            tmp = tmp / 10;
        }
        if (ans == i) break;
    }

    cout << ans;

    return 0;
}