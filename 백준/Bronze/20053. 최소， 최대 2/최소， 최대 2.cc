#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int max1;
int min1;
int n;
int a[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i == 0) {
				min1 = a[0];
				max1 = a[0];
			}
			else {
				if (a[i] > max1) {
					max1 = a[i];
				}
				else if (a[i] < min1) {
					min1 = a[i];
				}
			}
		}
		cout << min1 << " " << max1 << "\n";
		

	}


	return 0;
}