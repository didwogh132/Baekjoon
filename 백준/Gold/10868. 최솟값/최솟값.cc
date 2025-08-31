#include <iostream>
#include <algorithm>

using namespace std;

const int Max = 100010;
int n, m;
int arr[Max];
int tree[Max * 4];

int init(int node, int s, int e) {
    if (s == e) return tree[node] = s;
    int mid = (s + e) / 2;
    int left = init(node * 2, s, mid);
    int right = init(node * 2 + 1, mid + 1, e);
    return tree[node] = (arr[left] <= arr[right]) ? left : right;
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
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init(1, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        cout << arr[query(1, 0, n - 1, a -1 , b - 1)] << "\n";
    }

    return 0;
}