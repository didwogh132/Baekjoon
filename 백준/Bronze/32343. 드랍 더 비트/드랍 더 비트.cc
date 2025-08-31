#include <iostream>
#include <bitset>

using namespace std;

int main() {
    bitset<11> bits;

    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    if (n < a + b) {
        int num = (a + b) - n;
        for (int i = n - 1; i >= num; i--) {
            bits.flip(i);
        }
    }
    else {
        int num = n - (a + b);
        for (int i = n - 1; i >= num; i--) {
            bits.flip(i);
        }
    }

    cout << bits.to_ullong();

    return 0;
}