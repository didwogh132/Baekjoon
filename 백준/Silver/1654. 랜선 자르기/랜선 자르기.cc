#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    long long n;
    cin >> k >> n;

    vector<long long> len;
    long long hi = 0;
    for (int i = 0; i < k; i++) {
        long long a;
        cin >> a;
        len.push_back(a);
        if (a > hi) hi = a;
    }
    long long lo = 1, ans = 0;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += (len[i] / mid);
            if (cnt >= n)break;
        }
        if (cnt >= n) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    cout << ans;

    return 0;
}