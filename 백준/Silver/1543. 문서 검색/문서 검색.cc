#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

string arr;
string index1;
int arrLen;
int idxLen;
int Max;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	getline(cin, arr);
	getline(cin, index1);
	arrLen = arr.length();
	idxLen = index1.length();
	for (int i = 0; i <= arrLen - idxLen;) {
		bool flag = true;
		for (int j = 0; j < idxLen; j++) {
			if (arr[i + j] != index1[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cnt++;
			i += idxLen;
		}
		else {
			i++;
		}
	}

	cout << cnt;

	return 0;
}