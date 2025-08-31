#include <iostream>

using namespace std;

const int Max = 100010;
int arr[Max];
int tree_min[Max * 4];
int tree_max[Max * 4];
int n, m;
int a, b;

int init_min(int node, int s, int e) {
    if (s == e) return tree_min[node] = s;

    int mid = (s + e) / 2;
    int left = init_min(node * 2, s, mid);
    int right = init_min(node * 2 + 1, mid + 1, e);

    return tree_min[node] = (arr[left] <= arr[right]) ? left : right;
}
int init_max(int node, int s, int e) {
    if (s == e) return tree_max[node] = s;

    int mid = (s + e) / 2;
    int left = init_max(node * 2, s, mid);
    int right = init_max(node * 2 + 1, mid + 1, e);

    return tree_max[node] = (arr[left] >= arr[right]) ? left : right;
}

int query_min(int node, int s, int e, int l, int r) {
    if (r < s || l > e) return -1;
    if (l <= s && r >= e) return tree_min[node];

    int mid = (s + e) / 2;
    int left = query_min(node * 2, s, mid, l, r);
    int right = query_min(node * 2 + 1, mid + 1, e, l, r);
    if (left == -1) return right;
    if (right == -1) return left;
    return (arr[left] <= arr[right]) ? left : right;
}

int query_max(int node, int s, int e, int l, int r) {
    if (r < s || l > e) return -1;
    if (l <= s && r >= e) return tree_max[node];

    int mid = (s + e) / 2;
    int left = query_max(node * 2, s, mid, l, r);
    int right = query_max(node * 2 + 1, mid + 1, e, l, r);
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
    init_min(1, 0, n - 1);
    init_max(1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        cout << arr[query_min(1, 0, n - 1, a - 1, b - 1)] << " " << arr[query_max(1, 0, n - 1, a - 1, b - 1)] << "\n";
    }

    return 0;
}