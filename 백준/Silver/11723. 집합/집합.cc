#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    bitset<21> bits;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command.compare("add") == 0) {
            int idx;
            cin >> idx;
            bits.set(idx);
        }
        else if (command.compare("check") == 0) {
            int idx;
            cin >> idx;
            cout << bits.test(idx) << "\n";
        }
        else if (command.compare("remove") == 0) {
            int idx;
            cin >> idx;
            if (bits.test(idx)) {
                bits.flip(idx);
            }
        }
        else if (command.compare("toggle") == 0) {
            int idx;
            cin >> idx;
            bits.flip(idx);
        }
        else if (command.compare("all") == 0) {
            bits.set();
        }
        else if (command.compare("empty") == 0) {
            bits.reset();
        }
    }
    return 0;
}