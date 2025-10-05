#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n, m, b;
    int arr[501][501];
    int min = 258, max = 0;
    int ans, ans_time = INT_MAX;
    
    cin >> n >> m >> b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }

    int h = min;

    for (h = min; h <= max; h++) {
        int remove = 0;
        int add = 0;
        int time = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] < h) {
                    add += h - arr[i][j];
                }
                else if (arr[i][j] > h) {
                    remove += arr[i][j] - h;
                }
            }
        }

        if ((add - remove) > b) continue;
        else {
            time = add + (remove * 2);
            if (time <= ans_time) {
                ans_time = time;
                ans = h;
            }
        }
    }

    cout << ans_time << " " << ans;

    return 0;
}
