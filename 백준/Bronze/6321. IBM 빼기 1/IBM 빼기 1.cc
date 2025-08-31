#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        string num;
        cin >> num;

        for (int i = 0; i < num.size(); i++) {
            if (num[i] + 1 > 'Z') {
                num[i] = 'A';
            }
            else {
                num[i] += 1;
            }
        }

        cout << "String #" << tc << "\n";
        cout << num << "\n" << "\n";

    }
    return 0;
}