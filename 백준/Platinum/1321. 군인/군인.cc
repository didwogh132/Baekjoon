#include <iostream>

#define Max 500010
#define mod 1000000007

using namespace std;

int n, m;
int arr[Max];
int tree[Max * 4];

int init(int node, int s, int e) {
    if (s == e) return tree[node] = arr[s];

    int mid = (s + e) / 2;
    int left = init(node * 2, s, mid);
    int right = init(node * 2 + 1, mid + 1, e);

    return tree[node] = left + right;
}

void update(int node, int s, int e, int idx, int value) {
    if (idx < s || idx > e) return;
    if (s == e) {
        tree[node] += value;
        arr[idx] += value;
        return;
    }
    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, value);
    update(node * 2 + 1, mid + 1, e, idx, value);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int b) {
    if (s == e) return s;
    
    int mid = (s + e) / 2;
    if (tree[node * 2] >= b) {
        return query(node * 2, s, mid, b);
    }
    else {
        return query(node * 2 + 1, mid + 1, e, b - tree[node * 2]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init(1, 1, n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            update(1, 1, n, b, c);
        }
        else {
            cin >> b;
            cout << query(1, 1, n, b) << "\n";
        }
    }

    return 0;
}