#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n;
        char a;
        deque<char> ans;
        ans.clear();
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a;
            if (i == 0) {
                ans.push_front(a);
            }
            else {
                if (a <= ans.front()) {
                    ans.push_front(a);
                }
                else {
                    ans.push_back(a);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}