#include <iostream>
#include <string>

using namespace std;

int main() {

    int n;
    cin >> n;
    string name;
    cin >> name;
    int cnt = 0;
    
    for (int i = 0; i < name.size(); i++) {
        if (name[i] == '1') cnt++;
    }
    cout << cnt;

    return 0;
}