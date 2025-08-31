#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	int dat[31] = { 0 };
	int n;
	dat[0] = 1;

	for (int i = 0; i < 28; i++) {
		cin >> n;
		dat[n] = 1;
	}

	for (int i = 0; i < 31; i++) {
		if (dat[i] == 0) {
			cout << i << "\n";
		}
	}


	return 0;
}