#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;
    string num;
    getline(cin, num);
    for (int tc = 1; tc <= t; tc++) {
        
        int idx[26] = {};
        getline(cin, num);
        for (int i = 0; i < num.size(); i++) {
            if (num[i] >= 'a' && num[i] <= 'z') {
                idx[num[i] - 'a']++;
            }
            else if (num[i] >= 'A' && num[i] <= 'Z') {
                idx[num[i] - 'A']++;
            }
            else continue;
        }
        int cnt = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (idx[i] < cnt) cnt = idx[i];
            else continue;
        }
        if (cnt == 0) {
            cout << "Case " << tc << ": " << "Not a pangram" << "\n";
        }
        else if (cnt == 1) {
            cout << "Case " << tc << ": " << "Pangram!" << "\n";
        }
        else if (cnt == 2) {
            cout << "Case " << tc << ": " << "Double pangram!!" << "\n";
        }
        else if (cnt == 3) {
            cout << "Case " << tc << ": " << "Triple pangram!!!" << "\n";
        }

    }
    return 0;
}