#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct node {
    string problem;
    int n;

    bool operator<(const node& other) {
        return n < other.n;
    }
};

int main() {

    int n;
    cin >> n;

    vector<node> ans;

    ans.resize(n);
    for(int i =0; i < n; i++) {
        cin >> ans[i].problem >> ans[i].n;
    }
    sort(ans.begin(), ans.end());

    cout << ans[0].problem;
    return 0;
}