#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int used[1000005];

int main() {
    int n;
    cin >> n;

    memset(used, -1, sizeof(used));

    queue<int> q;
    q.push(n);
    used[n] = 0;

    while (!q.empty()) {
        int now = q.front(); q.pop();

        for (int i = 0; i < 3; i++) {
            int next = 0;
            if (i == 0) {
                if (now % 3 == 0) next = now / 3;
            }
            else if (i == 1) {
                if (now % 2 == 0) next = now / 2;
            }
            else next = now - 1;

            if (next == 0) continue;
            if (used[next] > used[now] + 1) {
                used[next] = used[now] + 1;
            }
            else if (used[next] > -1) continue;
            else {
                used[next] = used[now] + 1;
            }
            q.push(next);
        }
    }

    cout << used[1];

    return 0;
}