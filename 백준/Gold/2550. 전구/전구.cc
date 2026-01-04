#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr_idx(n+1, 0);
    vector<int> arr(n, 0);
    vector<int> bulb(n, 0);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr_idx[num] = i;
    }
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        bulb[i] = num;
        arr[i] = arr_idx[num];
    }

    vector<int> lis;
    vector<int> lis_idx;
    vector<int> parent(n, -1);

    for (int i = 0; i < n; i++) {
        int x = arr[i];

        int idx = lower_bound(lis.begin(), lis.end(), x) - lis.begin();

        if (idx == lis.size()) {
            lis.push_back(x);
            lis_idx.push_back(i);
        }
        else {
            lis[idx] = x;
            lis_idx[idx] = i;
        }

        if (idx > 0) parent[i] = lis_idx[idx - 1];
    }
    cout << lis.size() << "\n";

    vector<int> chosen;
    int cur = lis_idx[lis.size() - 1];

    while (cur != -1) {
        chosen.push_back(bulb[cur]);
        cur = parent[cur];
    }

    sort(chosen.begin(), chosen.end());

    for (int i = 0; i < chosen.size(); i++) {
        cout << chosen[i] << " ";
    }

    return 0;
}