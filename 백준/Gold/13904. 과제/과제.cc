#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
struct node {
    int day;
    int point;
    bool operator <(const node& right) const {
        if (point != right.point) return point > right.point;
        return day < right.day;
    }
};
vector<node> arr;
int visit[1010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int day, point;
        cin >> day >> point;
        arr.push_back({ day, point });
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        node a = arr[i];
        while (a.day >= 1) {
            if (visit[a.day] == 0) {
                visit[a.day] = a.point;
                break;
            }
            else {
                a.day--;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        ans += visit[i];
    }

    cout << ans;

    return 0;
}