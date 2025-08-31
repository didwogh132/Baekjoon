#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;
vector<string>arr;
map<string, int> arr2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		arr.push_back(name);
		arr2.insert({ name, i });
	}

	for (int i = 0; i < m; i++) {
		string num;
		cin >> num;
		if (isdigit(num[0])) {
			cout << arr[stoi(num) -1] << "\n";
		}
		else {
			cout << arr2.find(num)->second +1 << "\n";
		}
	}

	return 0;
}