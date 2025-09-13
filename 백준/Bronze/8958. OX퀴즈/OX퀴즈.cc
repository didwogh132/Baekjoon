#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        string arr;
        cin >> arr;
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'O') {
                cnt++;
                sum += cnt;
            }
            else if (arr[i] == 'X') {
                cnt = 0;
            }
        }
        cout << sum << "\n";
    }

    return 0;
}