#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int sum = 1;
    int a =1, b =1;
    
    for (int i = 1; i <= n; i++) {
        sum *= i;
        if (i == k) a = sum;
        if (i == n - k) b = sum;
    }

    cout << sum / (a * b);

    return 0;
}