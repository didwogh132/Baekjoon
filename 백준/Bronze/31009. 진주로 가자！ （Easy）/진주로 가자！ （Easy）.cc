#include <iostream>
#include <string>

using namespace std;

string station[1010];
int cost[1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ans_cost = 0;
    int ans_cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> station[i] >> cost[i];
        if (station[i] == "jinju") {
            ans_cost = cost[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (cost[i] > ans_cost) ans_cnt++;
    }

    cout << ans_cost << "\n" << ans_cnt;

    return 0;
}