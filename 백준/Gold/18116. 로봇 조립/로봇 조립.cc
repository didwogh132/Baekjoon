#include <iostream>

using namespace std;

int parent[1000001];
int sz[1000001];

int find(int x) {
    if (parent[x] == x) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    int ra = find(a);
    int rb = find(b);

    if (ra == rb) return;

    if (sz[ra] < sz[rb]) swap(ra, rb);

    parent[rb] = ra;
    sz[ra] += sz[rb];
    return;
}

int query_size(int x) {
    int rx = find(x);
    return sz[rx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i <= 1000000; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        char a;
        int b, c;
        cin >> a;
        if (a == 'I') {
            cin >> b >> c;
            unite(b, c);
        }
        else if (a == 'Q') {
            cin >> b;
            cout << query_size(b) << "\n";
        }
    }
    return 0;
}