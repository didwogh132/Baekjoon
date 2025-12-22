#include <iostream>
#include <vector>

using namespace std;

struct vel {
    int dist;
    int vel;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    vector<vel> limit;
    vector<vel> run;
    cin >> n >> m;
    limit.resize(n);
    run.resize(m);

    for (int i = 0; i < n; i++) cin >> limit[i].dist >> limit[i].vel;

    for (int i = 0; i < m; i++) cin >> run[i].dist >> run[i].vel;

    int i = 0;
    int j = 0;

    int remlimit = limit[0].dist;
    int remrun = run[0].dist;

    int ans = 0;

    while (i < n && j < m) {
        int use = remlimit < remrun ? remlimit : remrun;

        int diff = run[j].vel - limit[i].vel;
        if (diff > ans) ans = diff;

        remlimit -= use;
        remrun -= use;

        if (remlimit == 0) {
            i++;
            if (i < n) remlimit += limit[i].dist;
        }
        if (remrun == 0) {
            j++;
            if (j < m) remrun += run[j].dist;
        }
    }
    
    cout << ans;
    return 0;
}