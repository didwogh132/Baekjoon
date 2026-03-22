#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string n;
    
    while (true) {
        getline(cin, n);

        if (n.size() == 0) break;

        int a[] = { 0, 0, 0, 0 };

        for (int i = 0; i < n.size(); i++) {

            if (n[i] >= 'a' && n[i] <= 'z') {
                a[0]++;
            }
            else if (n[i] >= 'A' && n[i] <= 'Z') {
                a[1]++;
            }
            else if (n[i] >= '0' && n[i] <= '9') {
                a[2]++;
            }
            else a[3]++;
        }

        for (int i = 0; i < 4; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}