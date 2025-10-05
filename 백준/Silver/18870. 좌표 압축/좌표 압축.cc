#include <iostream>
#include <map>
#include <set>

using namespace std;

int n;
int arr[1000010];
set<int> used;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[i] = num;
        used.insert(num);
    }
    map<int, int> idxmap;
    int idx = 0;
    for (set<int>::iterator it = used.begin(); it != used.end(); it++) {
        idxmap[*it] = idx++;
    }

    for (int i = 0; i < n; i++) {
        cout << idxmap[arr[i]] << " ";
    }
    

    return 0;
}
