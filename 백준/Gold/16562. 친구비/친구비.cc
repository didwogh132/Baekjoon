#include <iostream>

using namespace std;

int n, m, k;
int parent[10010];
int cost[10010];
int visited[10010];

int find(int x) {
    if (parent[x] == x) return x;
    int root = find(parent[x]);

    return root;
}

void Union(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB) return ;
    if (cost[rootA] > cost[rootB]) parent[rootA] = rootB;
    else parent[rootB] = rootA;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        int now_cost;
        cin >> now_cost;
        cost[i] = now_cost;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    int total = 0;
    bool flag = true;

    for (int i = 1; i <= n; i++) {
        int n = find(i);
        if (visited[n] == 1) continue;
        else {
            if (total + cost[n] > k) {
                flag = false;
                break;
            }
            total += cost[n];
            visited[n] = 1;
        }
    }

    if (flag) {
        cout << total;
    }
    else {
        cout << "Oh no";
    }

    return 0;
}