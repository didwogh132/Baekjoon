#include <iostream>
#include <vector>

using namespace std;

int arr[1000010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	vector<int> lis;

	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		if (lis.empty() || lis[lis.size() - 1] < arr[i]) {
			lis.push_back(arr[i]);
		}
		else {
			int pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			lis[pos] = arr[i];
		}
	}

	cout << lis.size();

	return 0;
}