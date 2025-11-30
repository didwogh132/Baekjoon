#include <vector>
#include <queue>
#include <climits>
#include <memory.h>
#include <stdio.h>

using namespace std;

short k, n, r;
struct node {
    short num, line, cost;
    bool operator <(const node& right) const {
        return line > right.line;
    }
};
vector<node> arr[101];
vector<vector<short>> dist;
short ans = 32767;

void dijkstra(short num) {
    priority_queue<node> pq;
    pq.push({ num, 0, 0 });
    dist[0][num] = 0;
    while (!pq.empty()) {
        node now = pq.top(); pq.pop();
        if(dist[now.cost][now.num] < now.line || now.line >= ans) continue;
        if(now.num == n) {
            ans = (now.line < ans) ? now.line : ans;
            continue;
        }
        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            short nextline = now.line + next.line;
            short nextcost = now.cost + next.cost;

            if(nextcost > k || nextline >= ans || dist[nextcost][next.num] <= nextline) continue;
            dist[nextcost][next.num] = nextline;
            pq.push({ next.num, nextline, nextcost });
        }
    }
}

int main() {
    scanf("%hd %hd %hd", &k, &n, &r);

    dist.assign(k + 1, vector<short>(n + 1, 32767));
    for (int i = 0; i < r; i++) {
        short from, to, line, cost;
        scanf("%hd %hd %hd %hd", &from, &to, &line, &cost);
        arr[from].push_back({ to, line, cost });
    }
    dijkstra(1);
    if (ans == 32767) printf("-1");
    else printf("%hd", ans);
    return 0;
}