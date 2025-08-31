#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> yarr;
vector<int> xarr;

int main() {
    int y, x;
    cin >> y >> x;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == 1) {
            int ynum;
            cin >> ynum;
            yarr.push_back(ynum);
        }
        else {
            int xnum;
            cin >> xnum;
            xarr.push_back(xnum);
        }
    }
    yarr.push_back(0);
    yarr.push_back(y);
    xarr.push_back(0);
    xarr.push_back(x);
    sort(yarr.begin(), yarr.end());
    sort(xarr.begin(), xarr.end());
    int Max = 0;
    for (int i = 1; i < yarr.size(); i++) {
        for (int j = 1; j < xarr.size(); j++) {
            if ((yarr[i] - yarr[i - 1]) * (xarr[j] - xarr[j - 1]) > Max) {
                Max = (yarr[i] - yarr[i - 1]) * (xarr[j] - xarr[j - 1]);
            }
        }
    }
    cout << Max;
    return 0;
}