#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    map<string, int> cnt;
    int ans = 0;

    for (int i = 0; i < q; i++) {
        string name;
        char op;
        cin >> name >> op;

        if (op == '+') {
            cnt[name] += 1;
        }
        else {
            if (cnt[name] == 0) ans += 1;
            else cnt[name] -= 1;
        }
    }
    
    map<string, int>::iterator it;
    for (it = cnt.begin(); it != cnt.end(); it++) {
        ans += it->second; 
    }

    cout << ans;
    return 0;
}