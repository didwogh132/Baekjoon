#include <vector>
#include <queue>
#include <climits>
#include <memory.h>
#include <stdio.h>

using namespace std;

int k, n, r;
struct node {
    int num;
    int line;
    int cost;
    bool operator <(const node& right) const {
        return line > right.line;
    }
};
vector<node> arr[101];
vector<vector<int>> dist;
int ans = INT_MAX;

void dijkstra(int num) {
    priority_queue<node> pq;
    pq.push({ num, 0, 0 });
    dist[0][num] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (dist[now.cost][now.num] < now.line) continue;
        if(now.line >= ans ) continue;
        
        if(now.num == n) {
            ans = (now.line < ans) ? now.line : ans;
        }

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextline = now.line + next.line;
            int nextcost = now.cost + next.cost;

            if (nextcost > k) continue;
            if(nextline >= ans) continue;
            if (dist[nextcost][next.num] <= nextline) continue;
            dist[nextcost][next.num] = nextline;
            pq.push({ next.num, nextline, nextcost });
        }
    }
}

int main() {
    scanf("%d %d %d", &k, &n, &r);

    dist.assign(k + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 0; i < r; i++) {
        int from, to, line, cost;
        scanf("%d %d %d %d", &from, &to, &line, &cost);
        arr[from].push_back({ to, line, cost });
    }

    dijkstra(1);

    if (ans == INT_MAX) {
        printf("-1");
    }
    else {
        printf("%d", ans);
    }
    return 0;
}