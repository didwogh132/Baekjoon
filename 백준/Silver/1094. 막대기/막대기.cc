#include <iostream>
#include <bitset>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	bitset<7> bits(n);

	cout << bits.count();

	return 0;
}