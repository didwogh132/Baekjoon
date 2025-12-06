#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string n;
    cin >> n;

    for (int i = 0; i < n.size(); i++) {
        if (i % 10 == 0 && i != 0) cout << "\n";
        cout << n[i];
    }
    return 0;
}