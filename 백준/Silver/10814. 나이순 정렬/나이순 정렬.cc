#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int age;
	string name;
};
node arr[100010];
int n;
bool cmp(node a, node b){
	if (a.age < b.age) return true;
	if (a.age >= b.age) return false;

	//if (a.name.size() > b.name.size()) return true;
	//if (a.name.size() < b.name.size()) return false;
	//return false;
}

int main() {
	
	cin >> n;
	

	for (int i = 0; i < n; i++) {
		cin >> arr[i].age >> arr[i].name;
	}
	stable_sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i].age << " " << arr[i].name << "\n";
	}

	return 0;
}