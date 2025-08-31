#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;
int n, m;
int arr[100010];
int used[100010];
int a, b;
int sum;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}



	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		cout << arr[b] - arr[a-1] << "\n";
	}


	return 0;
}