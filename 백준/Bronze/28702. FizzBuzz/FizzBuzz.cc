#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string arr[3];
    int num = 0;
    int a = 0;
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];

        if (strcmp(arr[i].c_str(), "Fizz") == 0 || strcmp(arr[i].c_str(), "Buzz") == 0 || strcmp(arr[i].c_str(), "FizzBuzz") == 0) continue;
        else {
            num = stoi(arr[i]);
            a = i;
        }
    }
    if (a == 0) num += 3;
    else if (a == 1) num += 2;
    else num += 1;

    if (num % 15 == 0) cout << "FizzBuzz";
    else if (num % 5 == 0) cout << "Buzz";
    else if (num % 3 == 0) cout << "Fizz";
    else cout << num;

    return 0;
}