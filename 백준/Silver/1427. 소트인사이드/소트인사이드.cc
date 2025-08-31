#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;


int main() {
	string num;

	cin >> num;

	sort(num.begin(), num.end(), greater<>());

	cout << num;
	return 0;
}