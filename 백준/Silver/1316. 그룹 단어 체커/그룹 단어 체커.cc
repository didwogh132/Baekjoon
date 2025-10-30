#include <iostream>
#include <string.h>
#include <memory.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string word;
    bool visit[30];
    int ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> word;
        char now;
        char before = 0;
        bool flag = false;
        memset(visit, false, sizeof(visit));
        for (int j = 0; j < word.size(); j++) {
            now = word[j];
            if (j == 0) {
                before = word[j];
                visit[now - 'a'] = true;
            }
            if (before != now) {
                if (visit[now - 'a']) flag = true;
                else {
                    before = now;
                    visit[now - 'a'] = true;
                }
            }
            else continue;
        }
        if (!flag) ans++;
    }

    cout << ans;

    return 0;
}