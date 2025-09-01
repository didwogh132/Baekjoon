#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int start;
    int end;
    int cost;

    bool operator <(node right) {
        if (cost < right.cost) return true;
        if (cost > right.cost) return false;

        if (start < right.start) return true;
        if (start > right.start) return false;

        if (end < right.end) return true;
        if (end > right.end) return false;

        return false;
    }
};

int parent[100010];
node mst[1000010];

int find(int num) {
    if (num == parent[num]) return num;

    return parent[num] = find(parent[num]);
}

void Union(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB) return;

    parent[rootB] = rootA;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        mst[i] = { from, to, cost };
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    sort(mst, mst + m);

    int sum = 0;
    int connect = 0;

    for (int i = 0; i < m; i++) {
        node now = mst[i];

        if (connect == n - 2) break;
        if (find(now.start) == find(now.end)) continue;

        Union(now.start, now.end);
        connect++;
        sum += now.cost;
    }

    cout << sum;

    return 0;
}