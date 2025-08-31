#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int countArr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		countArr[num]++;
	}
	for (int i = 0; i < 10001; i++) {
		while(countArr[i]--)
		cout << i << "\n";
	}
	return 0;
}