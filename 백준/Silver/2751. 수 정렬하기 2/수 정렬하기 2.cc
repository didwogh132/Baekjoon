#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int arr[1000010];
bool cmp(int a, int b){
	return a < b;
}

int main() {
	int n;


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
	

	return 0;
}