#include <iostream>
#include <bitset>

using namespace std;

int main() {
    long long n;
    cin >> n;
    bitset<100> bits(n);
    long long num = 0;
    for (int i = 0; i < bits.size(); i++) {
        if (bits.test(i)) {
            long long idx = 1;
            for (int j = 0; j < i; j++) {
                if (i == 0) {
                    idx = 1;
                }
                else {
                    idx = idx * 3;
                }
            }
            num += idx;
        }
    }
    cout << num;
    
    return 0;
}