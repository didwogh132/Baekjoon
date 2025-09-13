#include <iostream>
#include <cstring>
#include <string>

using namespace std;


int main() {
    int used[26];
    memset(used, -1, sizeof(used));

    string arr;
    cin >> arr;

    for (int i = 0; i < arr.size(); i++) {
        if(used[arr[i] - 'a'] == -1) used[arr[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; i++) {
        cout << used[i] << " ";
    }
    return 0;
}