#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, p;
    cin >> a >> b >> c >> d >> p;
    int a_cost = a * p;
    int b_cost = b;

    if (p > c) {
        b_cost += (p - c) * d;
    }
    int ans = (a_cost > b_cost) ? b_cost : a_cost;
    cout << ans;
    return 0;
}