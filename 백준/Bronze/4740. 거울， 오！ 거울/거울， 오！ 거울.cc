#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        string n;
        getline(cin, n);
        if (n == "***") break;

        for (int i = n.size() - 1; i >= 0; i--) {
            cout << n[i];
        }
        cout << "\n";
    }

    return 0;
}