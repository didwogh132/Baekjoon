#include <iostream>
#include <string>

using namespace std;

int main() {
    string num;
    cin >> num;
    int a = 0;
    for (int i = 0; i < 13; i++) {
        if (num[i] == '*') a = i;
    }
    int n = 0;
    int ans = 0;
    
    for (int i = 0; i < 10; i++) {
        int sum = 0;
        for (int j = 0; j < 13; j++) {
            if (j == a && j % 2 == 1) sum += i * 3;
            else if (j == a && j % 2 == 0) sum += i;
            else if(j % 2 == 0){
                sum += (num[j] - '0');
            }
            else {
                sum += (num[j] - '0') * 3;
            }
        }
        if (sum % 10 == 0) ans = i;
    }

    cout << ans;

    return 0;
}