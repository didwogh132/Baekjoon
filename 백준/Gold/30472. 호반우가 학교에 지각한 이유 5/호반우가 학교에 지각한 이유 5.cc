#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
    long long s, e, diff;
    bool operator<(const node& other) {
        return diff > other.diff;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<node> arr;
    vector<long long> preh;
    preh.resize(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        arr.push_back({ s, e, s - e });
    }

    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++) {
        preh[i] = preh[i - 1] + arr[i - 1].diff;
    }

    long long minh = 0;
    for (int i = 1; i <= n; i++) {
        minh = min(minh, preh[i]);
    }

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (preh[i - 1] + arr[i - 1].s) - minh;
    }

    cout << sum;

    return 0;
}