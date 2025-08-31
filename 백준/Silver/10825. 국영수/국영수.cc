#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct node {
	string name;
	int kor;
	int eng;
	int math;
};
bool cmp(node a, node b) {
	if (a.kor < b.kor) return false;
	if (a.kor > b.kor) return true;

	if (a.eng < b.eng) return true;
	if (a.eng > b.eng) return false;

	if (a.math < b.math) return false;
	if (a.math > b.math) return true;

	if (a.name < b.name) return true;
	if (a.name > b.name) return false;

	return false;
}
int n;
node arr[100001];

int main() {

	cin >> n;

	for (int i = 0;i < n; i++) {
		cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math ;
	}
	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i].name << "\n";
	}

	return 0;
}