#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> order(k);
    for (int i = 0; i < k; i++) cin >> order[i];

    vector<int> plug;
    int ans = 0;

    for (int i = 0; i < k; i++) {
        int cur = order[i];

        bool exist = false;
        for (int j = 0; j < (int)plug.size(); j++) {
            if (plug[j] == cur) {
                exist = true;
                break;
            }
        }

        if (exist) continue;

        if ((int)plug.size() < n) {
            plug.push_back(cur);
            continue;
        }

        int removeIdx = -1;
        int farthest = -1;

        for (int j = 0; j < (int)plug.size(); j++) {
            int nextUse = -1;

            for (int t = i + 1; t < k; t++) {
                if (order[t] == plug[j]) {
                    nextUse = t;
                    break;
                }
            }

            if (nextUse == -1) {
                removeIdx = j;
                break;
            }

            if (nextUse > farthest) {
                farthest = nextUse;
                removeIdx = j;
            }
        }

        plug[removeIdx] = cur;
        ans++;
    }

    cout << ans;
    return 0;
}