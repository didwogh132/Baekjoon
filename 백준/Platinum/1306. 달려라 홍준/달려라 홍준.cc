#include <iostream>
#include <algorithm>

using namespace std;

const int Max = 1000010;
int arr[Max];
int tree[Max * 4];
int n, m;

int update(int node, int s, int e, int idx) {
    if (idx < s || idx > e) return tree[node];
    if (s == e) return tree[node] = idx;
    int mid = (s + e) / 2;
    int left = update(node * 2, s, mid, idx);
    int right = update(node * 2 + 1, mid + 1, e, idx);
    return tree[node] = (arr[left] >= arr[right]) ? left : right;
}

int query(int node, int s, int e, int l, int r) {
    if (r < s || l > e) return -1;
    if (l <= s && e <= r) return tree[node];
    int mid = (s + e) / 2;
    int left = query(node * 2, s, mid, l, r);
    int right = query(node * 2 + 1, mid + 1, e, l, r);

    if (left == -1) return right;
    if (right == -1) return left;

    return (arr[left] >= arr[right]) ? left : right;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i <= 2 * (m - 1) && i < n; i++) {
        update(1, 0, n - 1, i);
    }

    for (int i = m - 1; i <= n - m; i++) {
        int l = i - (m -1);
        int r = i + (m - 1);
        int idx = query(1, 0, n - 1, l, r);
        cout << arr[idx] << " ";

        if (r + 1 < n) update(1, 0, n - 1, r + 1);
        update(1, 0, n - 1, l);
    }

    return 0;
}