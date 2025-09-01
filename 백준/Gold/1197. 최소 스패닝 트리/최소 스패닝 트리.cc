#include <iostream>
#include <vector>
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

int parent[10005];
vector<node> mst;

int find(int n) {
    if (n == parent[n]) return n;

    return parent[n] = find(parent[n]);
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
        mst.push_back({ from, to, cost });
    }

    sort(mst.begin(), mst.end());

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int sum = 0;

    for (int i = 0; i < m; i++) {
        node now = mst[i];

        if (find(now.start) == find(now.end)) continue;

        Union(now.start, now.end);

        sum += now.cost;
    }

    cout << sum;


    return 0;
}