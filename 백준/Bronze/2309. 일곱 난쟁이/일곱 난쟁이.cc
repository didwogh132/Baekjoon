#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr(9);
vector<int> ans;
bool found = false;

void dfs(int idx, int cnt, int sum) {
    if(found) return;

    if(cnt == 7) {
        if(sum == 100) {
            sort(ans.begin(), ans.end());

            for(int i =0; i < ans.size(); i++) {
                cout << ans[i] << "\n";
            }
            found = true;
        }
        return;
    }

    if(idx == 9) return;

    ans.push_back(arr[idx]);
    dfs(idx + 1, cnt + 1, sum + arr[idx]);
    ans.pop_back();

    dfs(idx + 1, cnt , sum);
}

int main() {

    for(int i =0; i < 9; i++) cin >> arr[i];

    dfs(0, 0, 0);
    
    return 0;
}