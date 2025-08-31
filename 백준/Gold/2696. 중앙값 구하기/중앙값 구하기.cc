#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 1000010

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int> max;
    int num;
    int mid[10010];
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        memset(mid, 0, sizeof(mid));
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> num;
            if (max.empty() || max.top() >= num) {
                max.push(num);
            }
            else {
                min.push(num);
            }

            if (max.size() > min.size() + 1) {
                int move = max.top(); max.pop();
                min.push(move);
            }
            else if (min.size() > max.size()) {
                int move = min.top(); min.pop();
                max.push(move);
            }
            if (i % 2 == 1) {
                mid[cnt] = max.top();
                cnt++;
            }
        }

        cout << cnt << "\n";

        for (int i = 0; i < cnt; i++) {
            cout << mid[i] << " ";
        }
        cout << "\n";
        
        while(!max.empty()) max.pop();
        while(!min.empty()) min.pop();
    }
    
    return 0;
}