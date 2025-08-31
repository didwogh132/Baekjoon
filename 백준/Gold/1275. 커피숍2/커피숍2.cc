#include <iostream>
#include <algorithm>

using namespace std;

const int Max = 100010;
int n, m;
long long arr[Max];
long long tree[Max * 4];
long long x, y, a, b;

long long init(int node, int s, int e) {
    if (s == e) return tree[node] = arr[s];

    int mid = (s + e) / 2;
    long long left = init(node * 2, s, mid);
    long long right = init(node * 2 + 1, mid + 1, e);

    return tree[node] = left + right;
}

void update(int node, int s, int e, int idx, long long value) {
    if (idx < s || idx > e) return;
    if (s == e) {
        arr[idx] = value;
        tree[node] = value;
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, value);
    update(node * 2 + 1, mid + 1, e, idx, value);
    long long left = tree[node * 2];
    long long right = tree[node * 2 + 1];

    tree[node] = left + right;
}

long long query(int node, int s, int e, int l, int r) {
    if (r < s || l > e) return -1;
    if (l <= s && r >= e) return tree[node];

    int mid = (s + e) / 2;
    long long left = query(node * 2, s, mid, l, r);
    long long right = query(node * 2 + 1, mid + 1, e, l, r);
    if (left == -1) return right;
    if (right == -1) return left;
    return left + right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init(1, 1, n);

    for (int i = 0; i < m; i++) {
        cin >> x >> y >> a >> b;
        if (y <= x) swap(x, y);
        cout << query(1, 1, n, x, y) << "\n";
        update(1, 1, n, a, b);

    }
    
    return 0;
}