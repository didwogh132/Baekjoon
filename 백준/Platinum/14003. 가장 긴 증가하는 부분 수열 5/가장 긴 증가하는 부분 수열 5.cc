#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n;
int arr[1000005];
int pos[1000005];
int back_idx[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	vector<int> lis;
	vector<int> lis_idx;

	for (int i = 0; i < n; i++) {
		int now = arr[i];
		int idx = lower_bound(lis.begin(), lis.end(), now) - lis.begin();

		if (idx == lis.size()) {
			lis.push_back(now);
			lis_idx.push_back(i);
		}
		else {
			lis[idx] = now;
			lis_idx[idx] = i;
		}
		pos[i] = idx;

		if (idx > 0) {
			back_idx[i] = lis_idx[idx - 1];
		}
		else {
			back_idx[i] = -1;
		}
	}
	int length = lis.size();
	cout << length << "\n";

	int last_idx = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (pos[i] == length - 1) {
			last_idx = i;
			break;
		}
	}

	stack<int> st;

	while (last_idx != -1) {
		st.push(arr[last_idx]);
		last_idx = back_idx[last_idx];
	}

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}