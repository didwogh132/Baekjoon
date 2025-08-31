#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100010];
long long sumTree[400010];
int minTree[400010];

long long initSum(int node, int s, int e) {
    if (s == e) return sumTree[node] = arr[s];
    int m = (s + e) / 2;
    return sumTree[node] = initSum(node * 2, s, m) + initSum(node * 2 + 1, m + 1, e);
}

int initMin(int node, int s, int e) {
    if (s == e) return minTree[node] = s;
    int m = (s + e) / 2;
    int l = initMin(node * 2, s, m);
    int r = initMin(node * 2 + 1, m + 1, e);
    return minTree[node] = (arr[l] <= arr[r]) ? l : r;
}

long long querySum(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return sumTree[node];
    int m = (s + e) / 2;
    return querySum(node * 2, s, m, l, r) + querySum(node * 2 + 1, m + 1, e, l, r);
}

long long queryMin(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return -1;
    if (l <= s && e <= r) return minTree[node];
    int m = (s + e) / 2;
    int left = queryMin(node * 2, s, m, l, r);
    int right = queryMin(node * 2 + 1, m + 1, e, l, r);

    if (left == -1) return right;
    if (right == -1) return left;
    return (arr[left] <= arr[right]) ? left : right;
}

long long solve(int l, int r) {
    if (l > r) return 0;
    int minIdx = queryMin(1, 1, n, l, r);
    long long total = querySum(1, 1, n, l, r);
    long long now = total * arr[minIdx];

    long long left = solve(l, minIdx - 1);
    long long right = solve(minIdx + 1, r);

    return max({ now, left, right });
}

int main() {
    
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];
    initSum(1, 1, n);
    initMin(1, 1, n);
    cout << solve(1, n);

    return 0;
}