#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<int> arr[510];
vector<int> arr2[510];
int visited[501];
int visited2[501];
int cnt;
int cnt2;
int ans;

void bfs(int num) {
    queue<int>q;
    q.push(num);
    visited[num] = 1;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int i = 0; i < arr[now].size(); i++) {
            int next = arr[now][i];
            if (visited[next] > 0) continue;
            visited[next] = 1;
            q.push(next);
            cnt++;
        }
    }
}
void bfs2(int num) {
    queue<int>q2;
    q2.push(num);
    visited2[num] = 1;
    while (!q2.empty()) {
        int now = q2.front(); q2.pop();
        for (int i = 0; i < arr2[now].size(); i++) {
            int next = arr2[now][i];
            if (visited2[next] > 0) continue;
            visited2[next] = 1;
            q2.push(next);
            cnt2++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        arr[from].push_back(to);
        arr2[to].push_back(from);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        memset(visited2, 0, sizeof(visited2));
        cnt = 0;
        cnt2 = 0;
        bfs(i);
        bfs2(i);
        if (cnt + cnt2 >= n - 1) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}