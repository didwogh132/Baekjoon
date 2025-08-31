#include <iostream>

using namespace std;

int n, m;
int parent[500010];
int ans;

int find(int x) {
    if (parent[x] == x) return x;

    int root = find(parent[x]);

    return root;
}

void Union(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (parent[rootA] == parent[rootB]) return;
    else {
        if (rootA <= rootB) {
            parent[rootB] = rootA;
        }
        else {
            parent[rootA] = rootB;
        }
    }
}

bool Parent(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (Parent(a, b)) {
            if (ans == 0) {
                ans = i;
            }
        }
        Union(a, b);
    }

    if (ans > 0) {
        cout << ans;
    }
    else {
        cout << 0;
    }

    return 0;
}