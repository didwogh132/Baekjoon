#include <iostream>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		int num = i;
		while (num % 5 == 0) {
			num /= 5;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}