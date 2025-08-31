#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr[2010];
bool flag = false;
int visited[2010];

void dfs(int idx, int num) {
    if (flag) return;
    if (num >= 5) {
        flag = true;
        return;
    }
    visited[idx] = 1;
    for (int i = 0; i < arr[idx].size(); i++) {
        int next = arr[idx][i];
        if (visited[next] == 1) continue;
        dfs(arr[idx][i], num + 1);
    }
    visited[idx] = 0;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }

    for (int i = 0; i < n; i++) {
        if (flag) {
            break;
        }
        else {
            memset(visited, 0, sizeof(visited));
            dfs(i, 1);
        }
    }

    if (flag) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}