#include <iostream>
#include <queue>

using namespace std;

int s;
bool visited[3010];

struct node {
    int num;
    int copy;
    int time;
};

void bfs(int num, int copy,int time) {
    queue<node> q;
    q.push({ num, copy, time });
    visited[num] = time;

    while (!q.empty()) {
        node now = q.front(); q.pop();
        node next = now;
        
        if (next.num == s) {
            cout << next.time;
            return;
        }
        if (!visited[next.num]) {
            visited[next.num] = true;
            q.push({ next.num, next.num, next.time + 1 });
        }
        if (next.num + next.copy <= 2000) {
            q.push({ next.num + next.copy, next.copy, next.time + 1 });
        }
        if (next.num - 1 >= 0) {
            q.push({ next.num - 1, next.copy, next.time + 1 });
        }
    }
}

int main() {

    cin >> s;

    bfs(1, 0, 0);

    return 0;
}