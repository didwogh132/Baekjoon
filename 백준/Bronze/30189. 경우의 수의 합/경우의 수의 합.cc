#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for (int k = 0; k <= n + m; k++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if ((i + j) == k) cnt++;
                else if ((i + j) > k) break;
                else continue;
            }
        }
    }

    cout << cnt;
    return 0;
}