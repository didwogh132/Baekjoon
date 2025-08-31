#include <iostream>

using namespace std;

int n, m;
int parent[1000010];

int find(int x) {
    if (x == parent[x]) return x;
    int root = find(parent[x]);
    return root;
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

    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            Union(b, c);
        }
        else if (a == 1) {
            if (find(b) != find(c)) {
                cout << "NO" << "\n";
            }
            else {
                cout << "YES" << "\n";
            }
        }
    }
    return 0;
}