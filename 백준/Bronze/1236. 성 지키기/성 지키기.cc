#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
string arr[51];
int yarr[51];
int xarr[51];

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'X') {
                yarr[i] = 1;
                xarr[j] = 1;
            }
        }
    }
    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = 0; i < n; i++) {
        if (yarr[i] == 0) {
            cnt1++;
        }
    }
    for (int j = 0; j < m; j++) {
        if (xarr[j] == 0) {
            cnt2++;
        }
    }
    int cnt = max(cnt1, cnt2);
    cout << cnt;
    
    return 0;
}