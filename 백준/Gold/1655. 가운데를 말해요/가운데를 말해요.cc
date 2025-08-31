#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int> max;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (max.empty() || max.top() >= a) {
            max.push(a);
        }
        else {
            min.push(a);
        }

        if (max.size() > min.size() + 1) {
            int move = max.top(); max.pop();
            min.push(move);
        }
        else if (min.size() > max.size()) {
            int move = min.top(); min.pop();
            max.push(move);
        }


        cout << max.top() << "\n";
    }
    


    return 0;
}