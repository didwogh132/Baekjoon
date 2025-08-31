#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<string> arr;

bool cmp(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	return a < b;
}
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		arr.push_back(name);
	}
	
	sort(arr.begin(), arr.end(), cmp);
	auto it = unique(arr.begin(), arr.end());
	if (it != arr.end()) {
		arr.erase(it, arr.end());
	}

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}