#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    cout << a + b - c << "\n";
    string as = to_string(a);
    string bs = to_string(b);
    string name = as + bs;
    int num = stoi(name);

    cout << num - c;

    return 0;
}