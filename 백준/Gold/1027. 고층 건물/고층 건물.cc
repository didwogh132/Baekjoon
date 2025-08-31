#include <iostream>

typedef long long ll;

using namespace std;


int main() {
    int n;
    cin >> n;
    ll arr[51];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt[51] = { 0 };
    int Max = 0;
    
    for (int i = 0; i < n; i++) {
        
        long double max_slope = -1e18;

        for (int j = i + 1; j < n; j++) {
            long double num = (long double)(arr[j] - arr[i]) / (long double)(j - i);
            if (num > max_slope) {
                cnt[i]++;
                cnt[j]++;
                max_slope = num;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] > Max) Max = cnt[i];
    }

    cout << Max;
    
    return 0;
}