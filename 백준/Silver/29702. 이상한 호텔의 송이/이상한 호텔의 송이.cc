#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	unsigned long long arr[65] = { 1 };
	int t;
	cin >> t;

	

	for (int i = 1; i < 65; i++) {
		arr[i] = arr[i - 1] * 2;
	}
	for (int tc = 0; tc < t; tc++) {
		unsigned long long n;
		int num = 0;
		cin >> n;
		bitset<64> bits(n);
		for (int i = 0; i < 64; i++) {
			if (n > arr[i]) continue;
			else if (n == arr[i]) {
				num = i + 1;
				break;
			}
			else {
				num = i;
				break;
			}
		}
		while(1){
			cout << num;
			unsigned long long room = bits.to_ullong() - arr[num -1] + 1;
			string temp = to_string(room);
			
			if (temp.size() < 18) {
				for (int j = 0; j < 18 - temp.size(); j++) {
					cout << '0';
				}
				cout << temp << "\n";
			}
			else {
				cout << temp << "\n";
			}
			bits >>= 1;
			num--;
			if (num == 0) break;
		}
	}

	return 0;
}