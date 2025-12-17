#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, n, k;
    cin >> a >> b >> n >> k;

    int ans_a= 1, ans_b= 1;
    
    while (k > 0) {
        if (ans_b > b) {
            ans_a++;
            ans_b = 1;
        }
        else {
            if (k > n) {
                ans_b++;
                k -= n;
            }
            else {
                cout << ans_a << " " << ans_b;
                break;
            }
        }
    }
    return 0;
}