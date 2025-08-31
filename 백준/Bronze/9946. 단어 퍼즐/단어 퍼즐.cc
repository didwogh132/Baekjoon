#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int tc = 1;
    while(true) {
        string arr;
        string arr2;
        
        bool flag = true;

        cin >> arr >> arr2;
        if (arr == "END" && arr2 == "END") break;

        sort(arr.begin(), arr.end());
        sort(arr2.begin(), arr2.end());
        for (int i = 0; i < arr.size() || i < arr2.size(); i++) {
            if (arr[i] != arr2[i]) {
                flag = false;
                break;
            }
            else continue;
        }

        if (flag) {
            cout << "Case " << tc << ": same\n";
        }
        else {
            cout << "Case " << tc << ": different\n";
        }
        tc++;
    }
    return 0;
}