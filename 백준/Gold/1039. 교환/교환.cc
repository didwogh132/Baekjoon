#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

string n;
int k;
bool visited[11][1000010];
struct node {
    string a;
    int time;
};

void bfs(string a, int num) {
    queue<node>q;
    q.push({a, num});
    visited[num][stoi(a)] = true;

    while (!q.empty()) {
        node now = q.front(); q.pop();

        if (now.time == k) continue;

        for (int i = 0; i < now.a.size(); i++) {
            for (int j = i + 1; j < now.a.size(); j++) {
                string next = now.a;
                next[i] = now.a[j];
                next[j] = now.a[i];

                if (next[0] == '0') continue;
                int x = stoi(now.a);
                int y = stoi(next);
                if (visited[now.time + 1][y] == true) continue;
                visited[now.time + 1][y] = true;

                q.push({next, now.time+1});
            }
        }
    }
}

int main() {
    memset(visited, false, sizeof(visited));

    cin >> n >> k;

    bfs(n, 0);

    int ans = 0;

    for (int i = 1; i <= 1000000; i++) {
        if (visited[k][i]) {
            if (i > ans) ans = i;
        }
    }

    if (ans == 0) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}
