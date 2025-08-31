#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
struct node {
	int weight;
	int height;
};
bool cmp(node a, node b) {
	if (a.weight > b.weight) return true;
	if (a.weight < b.weight) return false;
	return false;
}

int main() {
	int n;
	node arr[51];
	int rank[51] = { 0 };
	int num = 1;
	int cnt;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].weight >> arr[i].height;
	}

	for (int i = 0; i < n; i++) {
		cnt = 1;
		for (int j = 0; j < n; j++) {
			if (arr[i].weight < arr[j].weight && arr[i].height < arr[j].height) {
				cnt++;
			}
		}
		rank[i] = cnt;
	}
	for (int i = 0; i < n; i++) {
		cout << rank[i] << " ";
	}

	return 0;
}