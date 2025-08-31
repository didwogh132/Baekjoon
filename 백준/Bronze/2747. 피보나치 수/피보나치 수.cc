#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int main() {
    int n1 = 0;
    int n2 = 1;
    int n3 = 1;
    arr.push_back(n1);
    arr.push_back(n2);
    arr.push_back(n3);
    for(int i = 3; i < 50; i++) {
        int num = arr[i -1] + arr[i - 2];
        arr.push_back(num);
    }
    int n;
    cin >> n;
    cout << arr[n];
    return 0;
}