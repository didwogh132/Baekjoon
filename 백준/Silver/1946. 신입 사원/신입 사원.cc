#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;


struct data1 {
	int a;
	int b;
};

int cmp(data1 c, data1 d) {
	return c.a < d.a;
}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		int num = 0;
		int cnt = 1;

		data1 arr[100000];

		for (int i = 0; i < n; i++) {
			cin >> arr[i].a >> arr[i].b;
		}
		sort(arr, arr + n, cmp);
		num = arr[0].b;
		for (int i = 0; i < n; i++) {
			if (arr[i].b < num) {
				cnt++;
				num = arr[i].b;
			}
		}
		cout << cnt << "\n";
	}
}