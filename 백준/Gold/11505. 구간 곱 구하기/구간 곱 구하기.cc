#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int mod = 1000000007;
const int Max = 1000010;
int n, m, k;
int arr[Max];
int tree[Max * 4];
int a, b, c;

int init(int node, int s, int e) {
    if (s == e) return tree[node] = arr[s] % mod;

    int mid = (s + e) / 2;
    int left = init(node * 2, s, mid);
    int right = init(node * 2 + 1, mid + 1, e);

    return tree[node] = (1LL * left * right) % mod;
}

void update(int node, int s, int e, int idx, int value) {
    if (s == e) {
        arr[idx] = value;
        tree[node] = arr[idx] % mod;
        return;
    }
    int mid = (s + e) / 2;
    if (idx <= mid) update(node * 2, s, mid, idx, value);
    else update(node * 2 + 1, mid + 1, e, idx, value);
    int left = tree[node * 2];
    int right = tree[node * 2 + 1];
    tree[node] = (1LL * left * right) % mod;
}

int query(int node, int s, int e, int l, int r) {
    if (r < s || l > e) return 1;
    if (l <= s && r >= e) return tree[node];

    int mid = (s + e) / 2;
    int left = query(node * 2, s, mid, l, r);
    int right = query(node * 2 + 1, mid + 1, e, l, r);

    return (1LL * left * right) % mod;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init(1, 1, n);

    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 1, n, b, c);
        }
        else if (a == 2) {
            cout << query(1, 1, n, b, c) << "\n";
        }
    }
    
    return 0;
}