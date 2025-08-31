#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

long long n, m;
int cnt = INT_MAX;
struct node {
    long long num;
    int time;
};
void bfs(long long start, int now_time) {
    queue<node> q;
    q.push({ start, now_time });

    while (!q.empty()) {
        node now = q.front(); q.pop();
        if (now.num > m) continue;

        for (int i = 0 ; i < 2; i++) {
            long long next;
            if (i == 0) next = now.num * 2;
            else next = now.num * 10 + 1;
            if (next > m) continue;
            q.push({ next, now.time + 1 });
            if (next == m && cnt > now.num + 1) cnt = now.time + 1;

        }
    }
}

int main() {
    
    cin >> n >> m;

    bfs(n, 0);

    if (cnt == INT_MAX) {
        cout << -1;
    }
    else if (n == m) {
        cout << 0;
    }
    else {
        cout << cnt + 1;
    }
    return 0;
}