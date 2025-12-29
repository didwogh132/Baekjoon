#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int a = 0, b = 0;
    cin >> n;

    string x;
    cin >> x;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == 's') {
            a++;
        }
        else if (x[i] == 'b') {
            b++;
        }
    }
    if (a > b) cout << "security!";
    else if (a == b) cout << "bigdata? security!";
    else cout << "bigdata?";
    return 0;
}