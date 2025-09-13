#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string name;
    int cnt = 0;

    while (cin >> name) cnt++;
    cout << cnt;

    return 0;
}