#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int arr[1030][1030];
int arr2[1030][1030];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int sum = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			arr2[i][j] = arr[i][j];
			arr[i][j] +=  arr[i][j - 1];
		}
	}
	for (int i = 0; i < m; i++) {
		int y1, x1;
		int y2, x2;
		int sum = 0;
		cin >> y1 >> x1 >> y2 >> x2;
		for (int j = y1; j <= y2; j++) {
			if (y1 == y2 && x1 == x2) {
				break;
			}
			else if (y1 == y2 && x1 == 1) {
				break;
			}
			else if (y1 == y2) {
				break;
			}
			else if (x1 == 1) {
				sum += arr[j][x2];
			}
			else {
				sum += (arr[j][x2] - arr[j][x1 - 1]);
			}
		}
		if (y1 == y2 && x1 == x2) {
			cout << arr2[y2][x2] << "\n";
		}
		else if (y1 == y2 && x1 == 1) {
			cout << arr[y2][x2] << "\n";
		}
		else if (y1 == y2) {
			cout << arr[y2][x2] - arr[y1][x1 - 1] << "\n";
		}
		else {
			cout << sum << "\n";
		}

	}
}