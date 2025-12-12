#include <iostream>
#include <string.h>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    map<string,bool> a;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        a[name] = true;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;
        if (a[name]) ans++;
    }

    cout << ans;

    return 0;
}