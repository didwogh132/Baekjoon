#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct node {
    long long y;
    long long x;
};

int main() {
    int n;
    cin >> n;
    vector<node> arr;

    for (int i = 0; i < n; i++) {
        long long y, x;
        cin >> y >> x;
        arr.push_back({ y,x });
    }
    arr.push_back({ arr[0].y, arr[0].x });
    long double sum = 0;
    for (int i = 1; i < arr.size(); i++) {
        sum += arr[i].y * arr[i - 1].x - arr[i].x * arr[i - 1].y;
    }

    cout << fixed << setprecision(1) << abs(sum) / 2;

    return 0;
}