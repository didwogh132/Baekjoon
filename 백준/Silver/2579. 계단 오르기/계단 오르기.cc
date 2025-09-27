#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct node {
    int num;
    int sum;
    int cnt;
};

int main() {
    int n;
    cin >> n;
    int arr[305];
    int used[305][3];
    memset(arr, 0, sizeof(arr));
    memset(used, 0, sizeof(used));

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    queue<node> q;
    q.push({0, 0, 0});
    used[0][0] = 0;

    while (!q.empty()) {
        node now = q.front(); q.pop();

        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                int num = now.num + 1;
                int sum = now.sum + arr[num];
                int cnt = now.cnt + 1;

                if (cnt == 3) continue;
                if (num > n) continue;
                if (used[num][cnt] >= sum) continue;
                used[num][cnt] = sum;
                q.push({ num, sum, cnt });
            }
            else {
                int num = now.num + 2;
                int sum = now.sum + arr[num];
                int cnt = 1;
                if (num > n) continue;
                if (used[num][cnt] >= sum) continue;
                used[num][cnt] = sum;
                q.push({ num, sum, cnt });
            }
        }
    }

    int ans = -1;
    if (used[n][1] > ans) ans = used[n][1];
    if (used[n][2] > ans) ans = used[n][2];

    cout << ans;


    return 0;
}