#include <iostream>
#include <string>

using namespace std;

int n;
int m;
string s;
int cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    cin >> s;
    int x = 0;
    int pattern = 0;
    while (x < m-2) {
        if (s[x] == 'I' && s[x + 1] == 'O' && s[x + 2] == 'I') {
            pattern++;
            if (pattern == n) {
                cnt++;
                pattern--;
            }
            x += 2;
        }
        else {
            x++;
            pattern = 0;
        }
    }

    cout << cnt;

    return 0;
}