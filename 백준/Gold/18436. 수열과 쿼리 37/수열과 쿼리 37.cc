#include <iostream>

using namespace std;

const int Max = 100010;
int arr[Max];
int n, m;
int odd_tree[Max * 4];

int odd_init(int node, int s, int e) {
    if (s == e) {
        if (arr[s] % 2 == 1) {
            return odd_tree[node] = 1;
        }
        else {
            return odd_tree[node] = 0;
        }
    }
    int mid = (s + e) / 2;
    int left = odd_init(node * 2, s, mid);
    int right = odd_init(node * 2 + 1, mid + 1, e);

    return odd_tree[node] = left + right;
}

void odd_update(int node, int s, int e, int idx, int value) {
    if (idx < s || idx > e) return;
    if (s == e) {
        if (value % 2 == 1) {
            odd_tree[node] = 1;
            return;
        }
        else {
            odd_tree[node] = 0;
            return;
        }
    }
    
    int mid = (s + e) / 2;
    odd_update(node * 2, s, mid, idx, value);
    odd_update(node * 2 + 1, mid + 1, e, idx, value);
    int left = odd_tree[node * 2];
    int right = odd_tree[node * 2 + 1];

    odd_tree[node] = left + right;
}

int odd_query(int node, int s, int e, int l, int r) {
    if (r < s || l > e) return 0;
    if (l <= s && r >= e) return odd_tree[node];

    int mid = (s + e) / 2;
    return odd_query(node * 2, s, mid, l, r) + odd_query(node * 2 + 1, mid + 1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    odd_init(1, 1, n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            if ((arr[b] % 2) != (c % 2)) {
                odd_update(1, 1, n, b, c);
            }
            arr[b] = c;
        }
        else if (a == 2) {
            int total = c - b + 1;
            cout << total - odd_query(1, 1, n, b, c) << "\n";
        }
        else if (a == 3) {
            cout << odd_query(1, 1, n, b, c) << "\n";
        }
        
    }

    return 0;
}