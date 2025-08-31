#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<string, string> dict;
    for (int i = 0; i < n; i++) {
        string word, meaning;
        cin >> word >> meaning;
        dict[word] = meaning;
    }

    string dummy;
    getline(cin, dummy);

    for (int i = 0; i < m; i++) {
        string line;
        getline(cin, line);
        bool printed = false;

        for (int pos = 0; pos < (int)line.size(); pos++) {
            string temp = "";
            for (int len = 1; pos + len <= (int)line.size(); len++) {
                temp += line[pos + len - 1];
                auto it = dict.find(temp);
                if (it != dict.end()) {
                    cout << it->second;
                    printed = true;
                }
            }
        }

        if (!printed) cout << "-1\n";
        else {
            cout << "\n";
        }
    }
    return 0;
}
