#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string arr[1001];

int main() {

	string num;
	cin >> num;

	string a = "";

	for (int i = num.size() - 1; i >= 0; i--) {
		a = num[i] + a;
		arr[i] = a;
	}

	sort(arr, arr + num.size());

	for (int i = 0; i < num.size(); i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}