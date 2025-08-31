#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std;

int n;
int arr[32][32];
long long visited[32][32][3];

int main() {
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    visited[0][1][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) continue;
            if (i - 1 >= 0) {
                visited[i][j][1] += visited[i - 1][j][1] + visited[i - 1][j][2];
            }

            if (j - 1 >= 0) {
                visited[i][j][0] += visited[i][j - 1][0] + visited[i][j - 1][2];
            }

            if (i - 1 >= 0 && j - 1 >= 0) {
                if (arr[i - 1][j] == 0 && arr[i][j - 1] == 0) {
                    visited[i][j][2] += visited[i - 1][j - 1][0] + visited[i - 1][j - 1][1] + visited[i - 1][j - 1][2];
                }
            }
        }
    }
    
    cout << visited[n - 1][n - 1][0] + visited[n - 1][n - 1][1] + visited[n - 1][n - 1][2];
    return 0;
}