#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r;
vector<vector<int>> arr;
vector<int> visit;
int vis = 1;

void dfs(int num) {
    visit[num] = vis++;

    for (int i = 0; i < arr[num].size(); i++) {
        if (!visit[arr[num][i]]) {
            dfs(arr[num][i]);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> r;

    arr.resize(n + 1);
    visit.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }

    for (int i = 1; i <= n; i++) {
        sort(arr[i].begin(), arr[i].end());
    }

    dfs(r);

    for (int i = 1; i <= n; i++) {
        cout << visit[i] << "\n";
    }
    return 0;
}