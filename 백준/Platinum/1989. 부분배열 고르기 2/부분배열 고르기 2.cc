#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int arr[100010];
long long psum[100010];
int tree[400010];
int ansL;
int ansR;
long long maxValue = LLONG_MIN;

int init(int node, int s, int e) {
    if (s == e) return tree[node] = s;
    int mid = (s + e) / 2;
    int left = init(node * 2, s, mid);
    int right = init(node * 2 + 1, mid + 1, e);
    return tree[node] = (arr[left] < arr[right] ? left : right);
}

int query(int node, int s, int e, int l, int r) {
    if (r < s || l > e) return -1;
    if (l <= s && e <= r) return tree[node];
    int mid = (s + e) / 2;
    int left = query(node * 2, s, mid, l, r);
    int right = query(node * 2 + 1, mid + 1, e, l, r);
    if (left == -1) return right;
    if (right == -1) return left;
    return arr[left] < arr[right] ? left : right;
}
void solve(int l, int r) {
    if (l > r) return;

    int minIdx = query(1, 1, n, l, r);
    long long total = psum[r] - psum[l - 1];
    long long value = total * arr[minIdx];

    if (value > maxValue) {
        maxValue = value;
        ansL = l;
        ansR = r;
    }

    solve(l, minIdx - 1);
    solve(minIdx + 1, r);
}


int main() {
    
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        psum[i] = arr[i] + psum[i - 1];
    }
    init(1, 1, n);
    solve(1, n);
    cout << maxValue << "\n";
    cout << ansL << " " << ansR;

    return 0;
}