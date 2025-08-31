#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<char> num;
    string name;

    cin >> name;
    int cnt = 0;
    for (int i = 0; i < name.size(); i++) {
        if (i == 0) {
            num.push_back(name[i]);
        }
        else {
            for (int j = num.size() -1; j >= 0; j--) {
                if (num[j] < name[i] && cnt < k) {
                    num.pop_back();
                    cnt++;
                }
                else break;
            }
            if (cnt == k) {
                num.push_back(name[i]);
            }
            else {
                num.push_back(name[i]);
            }

        }
    }
    int nums = 0;
    if (cnt < k) {
        nums = k - cnt;
    }
    for (int i = 0; i < num.size() - nums; i++) {
        cout << num[i];
    }

    return 0;
}