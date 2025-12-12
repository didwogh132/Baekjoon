#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string num;
    cin >> num;

    long long a = 0, b = 0;
    char cal;
    for (int i = 1; i < num.size(); i++) {
        if (num[i] == '+' || num[i] == '-' || num[i] == '*' || num[i] == '/') {
            cal = num[i];
            int a_low = 0;
            int b_low = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (num[j] == '-') {
                    a = a * (-1);
                }
                else {
                    a += (num[j] - '0') * pow(8, a_low++);
                }
            }
            for (int j = num.size() -1 ; j >= i + 1; j--) {
                if (num[j] == '-') {
                    b = b * (-1);
                }
                else {
                    b += (num[j] - '0') * pow(8, b_low++);
                }
            }
            break;
        }
    }
    long long ans_10;
    if (cal == '+') {
        ans_10 = a + b;
    }
    else if (cal == '-') {
        ans_10 = a - b;
    }
    else if (cal == '*') {
        ans_10 = a * b;
    }
    else if (cal == '/') {
        if (b == 0) {
            cout << "invalid";
            return 0;
        }
        else {
            ans_10 = a / b;
            if ((a % b != 0) && ((a < 0) ^ (b < 0))) {
                ans_10 -= 1;
            }
        }
    }

    if (ans_10 == 0) {
        cout << 0;
        return 0;
    }
    long long x = ans_10;
    if (x < 0) {
        cout << "-";
        x = -x;
    }

    string ans;
    while (x > 0) {
        ans.push_back(char('0' + (x % 8)));
        x /= 8;
    }
    reverse(ans.begin(), ans.end());

    cout << ans;

    return 0;
}