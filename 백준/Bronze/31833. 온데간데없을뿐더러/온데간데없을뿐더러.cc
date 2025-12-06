#include <iostream>

using namespace std;

int main() {
    
    int n;
    long long a[10];
    long long b[10];
    long long as = 0, bs = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 10) {
            as = as * 10 + a[i];
        }
        else {
            as = as * 100 + a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] < 10) {
            bs = bs * 10 + b[i];
        }
        else {
            bs = bs * 100 + b[i];
        }
    }
    
    if (as <= bs) cout << as;
    else cout << bs;

    return 0;
}