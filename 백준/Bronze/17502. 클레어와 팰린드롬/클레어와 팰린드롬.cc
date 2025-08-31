#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string num;
    cin >> num;

    for (int i = 0; i < (n / 2) + 1; i++) {
        if (num[i] != num[num.size() - 1 - i]) {
            if (num[i] == '?') {
                num[i] = num[num.size() - 1 - i];
            }
            else {
                num[num.size() - 1 - i] = num[i];
            }
        }
        else if (num[i] == '?' && num[num.size() - 1 - i] == '?') {
            num[i] = 'a';
            num[num.size() - 1 - i] = num[i];
        }
    }
    cout << num;
    return 0;
}