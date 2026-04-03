#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    cin >> a;

    int cnt = 0;
    size_t pos = a.find("DKSH");

    while(pos != string::npos) {
        cnt++;
        pos = a.find("DKSH", pos + 1);
    }

    cout << cnt;

    return 0;
}