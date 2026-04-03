#include <iostream>
#include <vector>

using namespace std;

int arr[101][101];

int main() {

    int n;
    cin >> n;

    for(int i =1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> visited(n+1, 0);
    vector<vector<int>> groups;

    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;

        vector<int> group;
        group.push_back(i);
        
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            
            if(arr[i][j] == 0) {
                if(visited[j]) {
                    cout << 0;
                    return 0;
                }
                group.push_back(j);
            }
        }

        if(group.size() < 2) {
            cout << 0;
            return 0;
        }

        for(int a = 0; a < group.size(); a++) {
            for(int b = 0; b < group.size(); b++) {
                int u = group[a];
                int v = group[b];

                if(arr[u][v] != 0) {
                    cout << 0;
                    return 0;
                }
            }
        }

        for(int a = 0; a < group.size(); a++) {
            visited[group[a]] = 1;
        }

        groups.push_back(group);
    }

    cout << groups.size() << "\n";

    for(int i =0; i < groups.size(); i++) {
        for(int j =0; j < groups[i].size(); j++) {
            cout << groups[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}