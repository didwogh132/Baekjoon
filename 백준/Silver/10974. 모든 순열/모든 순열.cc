#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int used[10];
int path[10];
int n;

void func(int now) {
	if (now >= n) {
		for (int i = 0; i < n; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (used[i] == 1) continue;
		path[now] = i;
		used[i] = 1;
		func(now + 1);
		path[now] = 0;
		used[i] = 0;
	}
}


int main() {
	
	cin >> n;

	func(0);
}