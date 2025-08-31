#include <iostream>
#include <algorithm>

#define Max 200010

using namespace std;

int dat[10];
int type_cnt, n;
int arr[Max];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int p = 0;
    int q = 0;
    int max_size = 0;

    for (p = 0; p <= n -1; p++) {
        while (q < n) {
            if (dat[arr[q]] == 0) {
                if (type_cnt == 2) {
                    break;
                }
                type_cnt++;
            }
            dat[arr[q]]++;
            q++;
        }
        max_size = max(max_size, q - p);

        dat[arr[p]]--;
        if (dat[arr[p]] == 0) {
            type_cnt--;
        }
    }

    cout << max_size;

    return 0;
}