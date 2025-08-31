#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;


int main() {
	int bingo[26][2] = {};
	int result[5][5] = {};
	int arr[25] = {};
	int number;
	int num;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int n;
			cin >> n;
			bingo[n][0] = i;
			bingo[n][1] = j;
		}
	}
	for (int i = 0; i < 25; i++) {
		cin >> arr[i];
	}

	for (int k = 0; k < 25; k++)  {
		result[bingo[arr[k]][0]][bingo[arr[k]][1]] = 1;
		int count2 = 0;
		for (int m = 0; m < 5; m++) {
			if (result[m][0] + result[m][1] + result[m][2] + result[m][3] + result[m][4] == 5) {
				count2++;
			}
		}
		for (int m = 0; m < 5; m++) {
			if (result[0][m] + result[1][m] + result[2][m] + result[3][m] + result[4][m] == 5) {
				count2++;
			}
		}
		if (result[0][0] + result[1][1] + result[2][2] + result[3][3] + result[4][4] == 5) {
			count2++;
		}

		if (result[0][4] + result[1][3] + result[2][2] + result[3][1] + result[4][0] == 5) {
			count2++;
		}
		if (count2 >= 3) {
			num = k + 1;
			break;
		}
	}
	cout << num;

	return 0;
}