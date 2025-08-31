#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int arr[1010][3];
int visit[3][1010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
            visit[i][0] = arr[0][i];
    }

    for (int j = 1; j < n; j++) {
        for (int k = 0; k < 3; k++) {
            int min_cost = INT_MAX;
            for (int i = 0; i < 3; i++) {
                if (k == i) continue;
                min_cost = min(min_cost, visit[i][j - 1] + arr[j][k]);
            }
            visit[k][j] = min_cost;
        }
    }

    int answer = min({ visit[0][n - 1], visit[1][n - 1], visit[2][n - 1] });

    cout << answer;

    return 0;
}