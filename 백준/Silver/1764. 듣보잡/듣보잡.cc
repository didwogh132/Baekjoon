#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    map<string, int> arr;

    for (int i = 0; i < n + m; i++) {
        string a;
        cin >> a;
        arr[a]++;
    }
    map<string, int> ::iterator it;

    int cnt = 0;
    vector<string> ans;
    for (it = arr.begin(); it != arr.end(); it++) {
        if (it->second == 2) {
            cnt++;
            ans.push_back(it->first);
        }
    }

    cout << cnt << "\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}