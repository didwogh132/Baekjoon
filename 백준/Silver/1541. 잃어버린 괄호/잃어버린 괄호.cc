#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;

    cin >> a;

    long long ans = 0;
    long long num = 0;
    bool mode = false;

    for (size_t i = 0; i < a.size(); i++) {
        char c = a[i];

        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        }
        else if (c == '+' || c == '-') {
            if (mode == false) ans += num;
            else ans -= num;
            num = 0;

            if (c == '-') mode = true;
        }
    }

    if (mode == false) ans += num;
    else ans -= num;

    cout << ans;
    
    return 0;
}
