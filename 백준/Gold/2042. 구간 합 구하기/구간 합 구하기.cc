#include <iostream>
#include <algorithm>

using namespace std;

const int Max = 1000010;
long long n, m, k;
long long arr[Max];
long long tree[Max * 4];
long long a, b, c;

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
        tree[node] = value;
        arr[idx] = value;
        return;
    }
    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, value);
    update(node * 2 + 1, mid + 1, e, idx, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;

    if (l <= s && r >= e) return tree[node];

    int mid = (s + e) / 2;
    long long left = query(node * 2, s, mid, l, r);
    long long right = query(node * 2 + 1, mid + 1, e, l, r);
    return left + right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init(1, 0,n - 1);

    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 0, n - 1, b - 1, c);
        }
        else if (a == 2) {
            cout << query(1, 0, n - 1, b - 1, c - 1) << "\n";
        }
    }

    return 0;
}