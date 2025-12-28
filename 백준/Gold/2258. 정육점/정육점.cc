#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct node {
    long long weight;
    long long price;
};

bool cmp(node& a, node& b) {
    if (a.price != b.price) return a.price < b.price;
    return a.weight > b.weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<node> meat;

    meat.resize(n);

    for (int i = 0; i < n; i++) cin >> meat[i].weight >> meat[i].price;

    sort(meat.begin(), meat.end(), cmp);

    long long ans = LLONG_MAX;
    long long weightsum = 0;
    long long samecost = 0;

    int prevprice = -1;

    for (int i = 0; i < n; i++) {
        weightsum += meat[i].weight;

        if (meat[i].price == prevprice) samecost += meat[i].price;
        else {
            prevprice = meat[i].price;
            samecost = meat[i].price;
        }

        if (weightsum >= m) {
            if (ans > samecost) ans = samecost;
        }
    }

    if (ans == LLONG_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}