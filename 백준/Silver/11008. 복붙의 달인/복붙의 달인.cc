#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        string a, b;
        cin >> a >> b;
        int cnt = 0;
        while (true) {
            if (a.find(b) == -1) {
                cnt += a.size();
                break;
            }
            else {
                cnt += a.find(b) + 1;
                a = a.substr(a.find(b) + b.size());
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}