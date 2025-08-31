#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void func(int n, int from, int by, int to) {
    if (n == 1) cout << from << " " << to << "\n";
    else {
        func(n - 1, from, to, by);
        cout << from << " " << to << '\n';
        func(n - 1, by, from, to);
    }
}

int main() {

    int n;

    cin >> n;

    string a = to_string(pow(2, n));
    int x = a.find('.');
    a = a.substr(0, x);
    a[a.length() - 1] -= 1;

    cout << a << "\n";

    if (n <= 20) {
        func(n, 1, 2, 3);
    }

    return 0;
}