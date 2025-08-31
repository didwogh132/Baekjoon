#include <iostream>
#include <bitset>

using namespace std;

int main() {
    long long n;
    cin >> n;
    bitset<32> bits(n);
    bitset<32> bit(n);
    for (int i = 0; i < 32; i++) {
        bits.flip(i);
    }
    long long num;
    num = bits.to_ullong() + 1;
    bits = num;
    bit = bit ^ bits;
    cout << bit.count();
    return 0;
}