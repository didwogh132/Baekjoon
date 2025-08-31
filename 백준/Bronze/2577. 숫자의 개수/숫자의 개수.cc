#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int main() {

	int a, b, c;
	cin >> a >> b >> c;
	int num;
	num = a * b * c;
	int used[10] = {};
	while (num > 0) {
		used[num % 10]++;
		num = num / 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << used[i] << "\n";
	}

	return 0;
}