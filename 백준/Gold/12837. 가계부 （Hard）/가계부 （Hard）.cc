#include <iostream>

#define Max 1000010

using namespace std;

int arr[Max];
long long tree[Max * 4];
int n, q;

void update(int node, int s, int e, int idx, int value) {
    if (idx < s || idx > e) return;
    if (s == e) {
        tree[node] += value;
        arr[idx] = value;
        return;
    }
    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, value);
    update(node * 2 + 1, mid + 1, e, idx, value);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int s, int e, int l, int r) {
    if (l > e || r < s) return -1;
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
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 1, n, b, c);
        }
        else {
            cout << query(1, 1, n, b, c) << "\n";
        }
    }

    return 0;
}