#include <iostream>
#include <deque>

using namespace std;

int n, l, arr[5000000];
struct node {
	int idx;
	int value;
};
deque<node> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> l;

	for (int i = 0; i < n; i++) cin >> arr[i];
	
	dq.push_back({ 0, arr[0] });
	cout << arr[0] << " ";
	for (int i = 1; i < n; i++) {
		while (!dq.empty() && dq.back().value > arr[i]) {
			dq.pop_back();
		}
		dq.push_back({ i, arr[i] });

		if (dq.front().idx <= i - l) dq.pop_front();

		cout << dq.front().value << " ";
	}

	return 0;
}