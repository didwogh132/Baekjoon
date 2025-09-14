#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[1001];

    memset(arr, 0, sizeof(arr));

    for (int i = 2; i <= 1000; i++) {
        if (arr[i] == 0) {
            int a = 2;
            while (a * i <= 1000) {
                arr[a * i] = 1;
                a++;
            }
        }
    }
    arr[1] = 1;
    int cnt = 0;
    int use;
    for (int i = 0; i < n; i++) {
        cin >> use;
        if (arr[use] == 0) cnt++;
    }

    cout << cnt;

    return 0;
}