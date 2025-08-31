#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string num;
	cin >> num;
	int dat[10] = {};
	int Max = 0;
	int index = 0;

	for (int i = 0; i < num.size(); i++) {
		if (num[i] - '0' == 9) {
			dat[6]++;
		}
		else {
			dat[num[i] - '0']++;
		}
	}
	dat[6] = dat[6] / 2 + dat[6] % 2;
	for (int i = 0; i < 9; i++) {
		if (dat[i] > Max) {
			Max = dat[i];
		}
	}
	cout << Max;

	return 0;
}