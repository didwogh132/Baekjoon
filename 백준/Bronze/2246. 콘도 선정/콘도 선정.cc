#include <iostream>
#include <algorithm>

using namespace std;

struct condo {
    int dist;
    int cost;
    bool operator<(const condo& right) const {
        if (dist != right.dist) return dist < right.dist;
        return cost < right.cost;
    }
};
condo arr[10010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].dist >> arr[i].cost;

    sort(arr, arr + n);

    int ans = 1;
    condo first = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].cost < first.cost) {
            ans++;
            first = arr[i];
        }
    }

    cout << ans;

    return 0;
}