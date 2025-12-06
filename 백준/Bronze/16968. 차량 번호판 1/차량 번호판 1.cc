#include <iostream>
#include <string.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string num;
    cin >> num;

    int ans = 0;
    for (int i = 0; i < num.size(); i++) {
        if (i == 0) {
            if (num[i] == 'd') {
                ans += 10;
            }
            else {
                ans += 26;
            }
        }
        else {
            if (num[i] == 'd') {
                if (num[i - 1] == num[i]) {
                    ans *= 9;
                }
                else {
                    ans *= 10;
                }
            }
            else {
                if (num[i - 1] == num[i]) {
                    ans *= 25;
                }
                else {
                    ans *= 26;
                }
            }
        }
    }

    cout << ans;

    return 0;
}