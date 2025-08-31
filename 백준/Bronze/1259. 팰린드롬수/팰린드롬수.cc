#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int main() {

	string c;
	while (true) {
		cin >> c;
		if (c == "0") break;

		int low, high;
		low = 0;
		high = c.size() - 1;
		bool flag = true;
		for (int i = 0; i < c.size() / 2; i++) {
			if (c[low] == c[high]) {
				low++;
				high--;
			}
			else if (low == high) {
				break;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}
	return 0;
}