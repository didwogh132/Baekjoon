#include <iostream>

using namespace std;

int main() {

    int a, b;
    cin >> a >> b;

    long long sum = 0;

    long long x = 0;
    for(int i =1; i <= a; i++) x += i;

    sum = x;
    
    for(int i = a + 1; i <= b; i++) {
        x += i;
        sum = sum * x;

        sum = sum % 14579;
    }

    cout << sum;
    
    return 0;
}