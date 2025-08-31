#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<char> arr[26];
vector<char> path1;
vector<char> path2;
vector<char> path3;
int visited[26];

void dfs(char start) {
	if (start == '.') {
		return;
	}
	path1.push_back(start);

	for (int i = 0; i < arr[start - 'A'].size(); i++) {
		char next = arr[start - 'A'][i];
		dfs(next);
		if (!visited[start - 'A']) {
			visited[start - 'A'] = true;
			path2.push_back(start);
		}
	}
	path3.push_back(start);
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		char from, to1, to2;
		cin >> from >> to1 >> to2;
		arr[from - 'A'].push_back(to1);
		arr[from - 'A'].push_back(to2);
	}

	dfs('A');

	for (int i = 0; i < path1.size(); i++) {
		cout << path1[i];
	}
	cout << "\n";
	for (int i = 0; i < path2.size(); i++) {
		cout << path2[i];
	}
	cout << "\n";
	for (int i = 0; i < path3.size(); i++) {
		cout << path3[i];
	}
	return 0;
}