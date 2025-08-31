#include <iostream>
#include <string>
#include <map>

using namespace std;

bool cmp(string a, string b) {
    if (a < b) return true;
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    map<string, int> idx;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        idx[name]++;
    }

    map<string, int>::iterator it;
    
    string ans;
    int max = 0;
    for (it = idx.begin(); it != idx.end(); it++) {
        if (it->second > max) {
            ans = it->first;
            max = it->second;
        }
        else if (it->second == max) {
            if (cmp(it->first, ans)) {
                ans = it->first;
            }
        }
    }

    cout << ans;

    return 0;
}