#include <iostream>
#include <algorithm>

using namespace std;

const int Max = 100010;
int n;
int arr[Max];
int tree[Max * 4];
int a, b, c;

int init(int node, int s, int e) {
    if (s == e) return tree[node] = s;
    int mid = (s + e) / 2;
    int left = init(node * 2, s, mid);
    int right = init(node * 2 + 1, mid + 1, e);

    return tree[node] = (arr[left] <= arr[right]) ? left : right;
}

void update(int node, int s, int e, int idx, int value) {
    if (idx < s || idx > e) return;

    if (s == e) {
        tree[node] = idx;
        arr[idx] = value;
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, value);
    update(node * 2 + 1, mid + 1, e, idx, value);
    int left = tree[node * 2];
    int right = tree[node * 2 + 1];

    tree[node] = (arr[left] <= arr[right]) ? left : right;
}

int query(int node, int s, int e, int l, int r) {
    if (r < s || l > e) return -1;
    if (l <= s && r >= e) return tree[node];

    int mid = (s + e) / 2;
    int left = query(node * 2, s, mid, l, r);
    int right = query(node * 2 + 1, mid + 1, e, l, r);
    if (left == -1) return right;
    if (right == -1) return left;

    return (arr[left] <= arr[right]) ? left : right;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init(1, 1, n);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 1, n, b, c);
        }
        else if (a == 2) {
            cout << arr[query(1, 1, n, b, c)] << "\n";
        }
    }
    return 0;
}