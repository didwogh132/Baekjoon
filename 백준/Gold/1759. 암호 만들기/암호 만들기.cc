#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int L;
int C;
int cnt;
int used[30];
char arr[30];
char path[16];

void func(int now) {
	if (now >= L) {
		cnt = 0;
		for (int i = 0; i < L; i++) {
			if (path[i] == 'a' || path[i] == 'e' || path[i] == 'i' || path[i] == 'o' || path[i] == 'u') {
				cnt++;
			}
		}
		if (cnt == 0) return;
		else if (cnt > L - 2) return;
		else {
			for (int i = 0; i < L; i++) {
				cout << path[i];
			}
			cout << "\n";
			return;
		}
	}

	for (int i = 0; i < C; i++) {
		if (used[i] == 1) continue;
		if (now > 0 && path[now - 1] > arr[i]) continue;
		used[i] = 1;
		path[now] = arr[i];
		func(now + 1);
		used[i] = 0;
		path[now] = 0;
	}
}

int main() {
	
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + C);

	func(0);


	return 0;
}