#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

int n, m, na, nt;
vector<int> agent;
vector<int> telephone;
struct node {
    int num;
    int cost;
    bool operator <(const node& right) const {
        return cost > right.cost;
    }
};
vector<node> arr[1001];
priority_queue<node> pq;
priority_queue<node> pq2;
int neo_dist[1001];
int agent_dist[1001];

void dijkstra() {
    while (!pq2.empty()) {
        node now = pq2.top(); pq2.pop();

        if (agent_dist[now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = now.cost + next.cost;

            if (agent_dist[next.num] <= nextcost) continue;
            agent_dist[next.num] = nextcost;
            pq2.push({ next.num, nextcost });
        }
    }
}

void dijkstra2() {
    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (neo_dist[now.num] < now.cost) continue;

        for (int i = 0; i < arr[now.num].size(); i++) {
            node next = arr[now.num][i];
            int nextcost = now.cost + next.cost;

            if (neo_dist[next.num] <= nextcost) continue;
            if (nextcost < agent_dist[next.num]) {
                neo_dist[next.num] = nextcost;
                pq.push({ next.num, nextcost });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        agent.clear();
        telephone.clear();
        
        cin >> n >> m >> na >> nt;

        fill(neo_dist, neo_dist + n, INT_MAX);
        fill(agent_dist, agent_dist + n, INT_MAX);

        for (int i = 0; i < n; i++) {
            arr[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            arr[from].push_back({ to, cost });
            arr[to].push_back({ from, cost });
        }
        pq.push({0, 0});
        neo_dist[0] = 0;

        for (int i = 0; i < na; i++) {
            int num;
            cin >> num;
            agent.push_back(num);
            pq2.push({ num, 0 });
            agent_dist[num] = 0;
        }
        for (int i = 0; i < nt; i++) {
            int num;
            cin >> num;
            telephone.push_back(num);
        }

        dijkstra();
        dijkstra2();

        int ans = INT_MAX;

        for (int i = 0; i < telephone.size(); i++) {
            if (neo_dist[telephone[i]] != INT_MAX) {
                ans = (neo_dist[telephone[i]] < ans) ? neo_dist[telephone[i]] : ans;
            }
        }
        if (ans == INT_MAX) {
            cout << "Neo may fight an Agent" << "\n";
        }
        else {
            cout << ans << "\n";
        }
    }
    return 0;
}