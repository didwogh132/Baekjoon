#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    map<int, long long> arr;
    map<int, int> cnt;
    const int MAXV = 10000;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        arr[i] = a;
        cnt[a]++;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        if (a == 1) {
            int x = b;
            int ok = 0;

            if (x == 0) {
                int c0 = (cnt.count(0) ? cnt[0] : 0);
                if (c0 >= 2) ok = 1;
                else if (c0 >= 1 && (n - c0 >= 1)) ok = 1;
            }
            else {
                for (int d = 1; (long long)d * (long long)d <= (long long)x && d <= MAXV; d++) { // ★
                    if (x % d != 0) continue;
                    int e = x / d;
                    if (e > MAXV) continue;

                    int cd = (cnt.count(d) ? cnt[d] : 0);
                    int ce = (cnt.count(e) ? cnt[e] : 0);

                    if (d == e) {
                        if (cd >= 2) { ok = 1; break; }
                    }
                    else {
                        if (cd >= 1 && ce >= 1) { ok = 1; break; }
                    }
                }
            }
            cout << ok << "\n";
        }
        else {
            int idx = b;
            int prev = (arr.count(idx) ? (int)arr[idx] : 0);
            if (prev != 0) {
                cnt[prev]--;
                if (cnt[prev] == 0) cnt.erase(prev);             
                arr[idx] = 0;                                    
                cnt[0]++;                                        
            }
        }
    }

    return 0;
}