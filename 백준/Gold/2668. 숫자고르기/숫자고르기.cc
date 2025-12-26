#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<bool> used;
vector<bool> done;
vector<int> ans;
int cnt;

void dfs(int num) {
    used[num] = true;

    if (!used[arr[num]]) {
        dfs(arr[num]);
    }
    else if (!done[arr[num]]) {
        ans.push_back(num);
        for (int i = arr[num]; i != num; i = arr[i]) {
            ans.push_back(i);
            cnt += 1;
        }
        cnt += 1;
    }
    done[num] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    arr.resize(n + 1);
    used.resize(n + 1, false);
    done.resize(n + 1, false);
    
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    cout << cnt << "\n";

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}