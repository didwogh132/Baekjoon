#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int Max = 100010;
int n;
int arr[Max];
int tree[Max * 4];
int max_size;

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

long long maxarea(int left, int right) {
	if (left > right) return 0;

	int mididx = query(1, 1, n, left, right);
	long long area = (long long)(right - left + 1) * arr[mididx];
	long long leftarea = maxarea(left, mididx - 1);
	long long rightarea = maxarea(mididx + 1, right);

	return max(area, max(leftarea, rightarea));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
	while(cin >> n) {
        if (n == 0) break;
		memset(arr, 0, sizeof(arr));
		memset(tree, 0, sizeof(tree));
		max_size = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		init(1, 1, n);

		cout << maxarea(1, n) << "\n";
	}

	return 0;
}