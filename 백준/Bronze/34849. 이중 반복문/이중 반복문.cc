#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n > 10000) cout << "Time limit exceeded";
    else cout << "Accepted";
    return 0;
}