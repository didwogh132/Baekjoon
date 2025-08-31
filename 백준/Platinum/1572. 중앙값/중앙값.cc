#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int Max = 65536;
int tree[Max * 4];
int arr[250001];
int n, k;
long long sum;

void update(int node, int start, int end, int index, int diff) {
    if (index < start || index > end) return;
    tree[node] += diff;
    if (start == end) return;

    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, diff);
    update(node * 2 + 1, mid + 1, end, index, diff);
}

int query(int node, int start, int end, int kth) {
    if (start == end) return start;

    int left_count = tree[node * 2];
    int mid = (start + end) / 2;

    if (left_count >= kth) {
        return query(node * 2, start, mid, kth);
    }
    else {
        return query(node * 2 + 1, mid + 1, end, kth - left_count);
    }
}

int main() {

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int center = (k % 2 == 0) ? (k / 2) : (k / 2 + 1);

    for (int i = 0; i < k; i++) {
        update(1, 0, Max - 1, arr[i], 1);
    }
    sum += query(1, 0, Max - 1, center);

    for (int i = k; i < n; i++) {
        update(1, 0, Max - 1, arr[i - k], -1);
        update(1, 0, Max - 1, arr[i], 1);
        sum += query(1, 0, Max - 1, center);
    }

    cout << sum;

    return 0;
}