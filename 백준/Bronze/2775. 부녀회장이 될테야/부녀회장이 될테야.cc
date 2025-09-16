#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int t;
    int k, n;
    int arr[15][15];
    int psum[15][15];
    memset(arr, 0, sizeof(arr));
    memset(psum, 0, sizeof(psum));
    for (int i = 1; i < 15; i++) {
        arr[0][i] = i + arr[0][i - 1];
        psum[0][i] = arr[0][i];
    }
    
    for (int i = 1; i < 15; i++) {
        for (int j = 1; j < 15; j++) {
            arr[i][j] = psum[i - 1][j];
        }
        for (int j = 1; j < 15; j++) {
            psum[i][j] = arr[i][j] + psum[i][j - 1];
        }
    }
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> k >> n;

        cout << arr[k][n] << "\n";
    }

    return 0;
}