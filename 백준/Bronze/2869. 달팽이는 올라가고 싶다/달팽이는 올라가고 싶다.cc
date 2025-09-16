#include <iostream>

using namespace std;

int main() {
    int a, b, v;
    cin >> a >> b >> v;

    int n = 0;
    int day = ((v - a) + (a - b -1))/ (a- b);

    cout << day + 1;

    return 0;
}