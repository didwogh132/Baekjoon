#include <iostream>
#include <bitset>

using namespace std;

bitset<40000000> bits;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n;
	while (cin >> n) {
		if (bits.test(n)) continue;
		else {
			bits.set(n);
			cout << n << " ";
		}
	}
	return 0;
}