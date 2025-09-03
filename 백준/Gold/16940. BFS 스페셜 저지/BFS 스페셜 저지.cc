#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n;
vector<int> arr[100010];
int visited[100010];
int seq[100010];
int mark[100010];
bool flag = true;

void bfs() {
    queue<int> q;
    visited[1] = 0;
    q.push(1);

    int idx = 1;

    while (!q.empty()) {
        int now = q.front(); q.pop();

        int cnt = 0;
        for (int i = 0; i < arr[now].size(); i++) {
            int v = arr[now][i];
            if (visited[v] == -1) {
                mark[v] = 1;
                cnt++;
            }
        }
        for (int i = 0; i < cnt; i++) {
            if (idx >= n) {
                flag = false;
                return;
            }
            int x = seq[idx];
            if (mark[x] == 0) {
                flag = false;
                return ;
            }

            visited[x] = visited[now] + 1;
            q.push(x);
            mark[x] = 0;
            idx++;
        }

        for (int i = 0; i < arr[now].size(); i++) {
            int v = arr[now][i];
            if (mark[v] == 1) mark[v] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(visited, -1, sizeof(visited));
    memset(mark, 0, sizeof(mark));

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int from, to;
        cin >> from >> to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }

    for (int i = 0; i < n; i++) cin >> seq[i];

    bfs();

    if (flag) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}