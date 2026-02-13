#include <iostream>
#include <bitset>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    bitset<200> bits;

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        bits.set(a);
    }

    for (long long t = 0; t < k; t++) {
        bitset<200> Left = (bits << 1);
        bitset<200> Right = (bits >> 1);

        if (bits.test(n - 1)) Left.set(0);
        else Left.reset(0);

        if (bits.test(0)) Right.set(n - 1);
        else Right.reset(n - 1);

        bitset<200> next = (Left ^ Right);

        if (n < 200) next.reset(n);

        bits = next;
    }

    cout << bits.count();
    return 0;
}