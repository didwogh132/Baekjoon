#include <iostream>
#include <queue>

using namespace std;

int n, m;
struct node {
    int num;
    int time;
};
int visited[2][500010];
int Time;

void bfs(int num) {
    queue<node> q;
    q.push({ num, 0 });
    visited[0][num] = 1;

    while (!q.empty()) {
        node now = q.front(); q.pop();

        int bro = m + now.time * (now.time + 1) / 2;
        if (bro > 500000) {
            cout << -1;
            return;
        }
        if (visited[now.time % 2][bro] == 1) {
            cout << now.time;
            return;
        }

        for (int i = 0; i < 3; i++) {
            int nextnum;
            int nexttime = now.time + 1;
            if (i == 0) nextnum = now.num * 2;
            else if (i == 1) nextnum = now.num + 1;
            else nextnum = now.num - 1;
            if (nextnum < 0 || nextnum > 500000) continue;
            if (visited[nexttime % 2][nextnum] == 0) {
                visited[nexttime % 2][nextnum] = 1;
                q.push({ nextnum, nexttime });
            }
        }
    }
}

int main() {

    cin >> n >> m;
    bfs(n);

    return 0;
}