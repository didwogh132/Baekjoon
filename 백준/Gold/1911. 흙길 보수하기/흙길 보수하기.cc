#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int s;
	int e;
};

bool cmp(node a, node b) {
    if (a.s != b.s) return a.s < b.s;
    return a.e < b.e;
}
vector<node> arr;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		arr.push_back({ s, e });
	}
	sort(arr.begin(), arr.end(), cmp);


    long long cnt = 0;
    int cur = 0;

    for (int i = 0; i < n; i++) {
        int s = arr[i].s;
        int e = arr[i].e;

        if (cur < s) cur = s;

        while (cur < e) {
            cur += l;
            cnt++;
        }
    }

	cout << cnt;

	return 0;
}