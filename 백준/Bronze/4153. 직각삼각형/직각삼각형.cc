#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}

		if (c == sqrt(a * a + b * b) || b == sqrt(a * a + c * c) || a == sqrt(c * c + b * b)) {
			cout << "right" << "\n";
		}
		else {
			cout << "wrong" << "\n";
		}
	}
	return 0;
}