#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string a;
    getline(cin, a);
    bool flag = false;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '(') {
            cout << "\n";
            for (int j = i + 1; j < a.size() - 1; j++) {
                cout << a[j];
            }
            flag = true;
            break;
        }
        cout << a[i];
    }
    if (!flag) {
        cout << "\n-";
    }
    return 0;
}