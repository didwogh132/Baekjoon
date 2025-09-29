#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct node {
    int num;
    char a;
};
node arr[10005];
int visited[10005];
int a, b;

void bfs(int num) {

    queue<int> q;

    q.push(num);
    arr[num] = { 0, 0 };

    while (!q.empty()) {
        int now = q.front(); q.pop();

        if (now == b) continue;

        for (int i = 0; i < 4; i++) {
            int next;
            if (i == 0) {
                next = (now * 2) % 10000;
                if (visited[next] > -1) continue;
                visited[next] = visited[now] + 1;
                arr[next] = { now, 'D' };
                q.push(next);
            }
            else if (i == 1) {
                next = (now + 9999) % 10000;
                if (visited[next] > -1) continue;
                visited[next] = visited[now] + 1;
                arr[next] = { now, 'S' };
                q.push(next);
            }
            else if (i == 2) {
                next = (now % 1000) * 10 + (now / 1000);
                if (visited[next] > -1) continue;
                visited[next] = visited[now] + 1;
                arr[next] = { now, 'L' };
                q.push(next);
            }
            else {
                next = (now % 10) * 1000 + (now / 10);
                if (visited[next] > -1) continue;
                visited[next] = visited[now] + 1;
                arr[next] = { now, 'R' };
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        
        memset(arr, 0, sizeof(arr));
        memset(visited, -1, sizeof(visited));
        cin >> a >> b;

        bfs(a);

        int x = b;
        string ans;

        while (x != a) {
            ans = arr[x].a + ans;

            x = arr[x].num;
        }

        cout << ans << "\n";
    }

    return 0;
}