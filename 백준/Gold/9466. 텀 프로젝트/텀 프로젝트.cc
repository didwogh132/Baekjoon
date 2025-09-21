#include <iostream>
#include <cstring>

using namespace std;

int n;
int arr[100010];
bool used[100010];
bool done[100010];
int cnt;

void dfs(int num) {
    used[num] = true;

    if (!used[arr[num]]) {
        dfs(arr[num]);
    }
    else if (!done[arr[num]]) {
        for (int i = arr[num]; i != num; i = arr[i]) {
            cnt += 1;
        }
        cnt += 1;
    }

    done[num] = true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        memset(used, false, sizeof(used));
        memset(done, false, sizeof(done));
        cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                dfs(i);
            }
        }

        cout << n - cnt << "\n";
    }

    return 0;
}