#include <iostream>
#include <algorithm>

using namespace std;

const int Max = 1000010;
int n, m;
long long tree[Max * 4];
long long a, b, c;

void update(int node, int s, int e, int idx, int value) {
    if (idx < s || idx > e) return;

    if (s == e) {
        tree[node] = value;
        return;
    }
    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, value);
    update(node * 2 + 1, mid + 1, e, idx, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int s, int e, int l, int r) {
    if (r < s || l > e) return 0;

    if (l <= s && r >= e) return tree[node];

    int mid = (s + e) / 2;
    long long left = query(node * 2, s, mid, l, r);
    long long right = query(node * 2 + 1, mid + 1, e, l, r);
    return left + right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 0) {
            if (b > c) swap(b, c);
            cout << query(1, 0, n - 1, b - 1, c - 1) << "\n";
        }
        else if (a == 1) {
            update(1, 0, n - 1, b - 1, c);
        }
    }

    return 0;
}