#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int path[9];


void func(int now) {
	if (now >= m) {
		for (int i = 0; i < now; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		path[now] = i;
		func(now + 1);
		path[now] = 0;

	}
}

int main() {
	
	

	cin >> n >> m;

	func(0);
	

	return 0;
}