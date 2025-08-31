#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;
struct node {
	int cost;
	int num;
};
bool cmp(node a, node b) {
	if (a.cost < b.cost) return false;
	if (a.cost > b.cost) return true;
	return false;
}

node arr[8];
int visit[5];

int main() {
	for (int i = 0; i < 8; i++) {
		int num;
		cin >> num;
		arr[i] = { num, i+1 };
	}
	sort(arr, arr + 8, cmp);

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += arr[i].cost;
		visit[i] = arr[i].num;
	}
	sort(visit, visit + 5);
	cout << sum << "\n";
	for (int i = 0; i < 5; i++) {
		cout << visit[i] << " ";
	}

	return 0;
}