#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int p, m, f, c;
        cin >> p >> m >> f >> c;
        int ticket_cnt = 0;
        int chicken_cnt1 = 0, chicken_cnt2 = 0;
        
        chicken_cnt1 = (m / p) + ((m / p) * c ) / f;
        chicken_cnt2 = (m / p);
        
        ticket_cnt = (m / p) * c;
        if (ticket_cnt >= f) {
            chicken_cnt2 += (ticket_cnt - f) / (f - c) + 1;
        }
        cout << chicken_cnt2 - chicken_cnt1 << "\n";

    }
    return 0;
}