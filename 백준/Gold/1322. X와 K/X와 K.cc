#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x;
	int k;
	cin >> x >> k;
	int cnt = 0;
	long long result = 0;
	int x_bit = 0;
	int k_bit = 0;
	while (x_bit < 64) {
		if ((x & (1LL << x_bit)) == 0) {
			if (k & (1LL << k_bit)) {
				result |= (1LL << x_bit);
			}
			k_bit++;
		}
		x_bit++;
	}

	cout << result;
	return 0;
}