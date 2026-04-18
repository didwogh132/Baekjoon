#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    vector<int> num;
    for (int i = n.size() - 1; i >= 0; i-= 3) {
        int x = 0;
        for (int j = i; j > i - 3 && j >= 0; j--) {
            if (j == i) {
                if (n[j] == '1') {
                    x += 1;
                }
            }
            else if (j == i - 1) {
                if (n[j] == '1') {
                    x += 2;
                }
            }
            else if (j == i - 2) {
                if (n[j] == '1') {
                    x += 4;
                }
            }
        }
        num.push_back(x);
    }

    for (int i = num.size() - 1; i >= 0; i--) {
        cout << num[i];
    }
    return 0;
}