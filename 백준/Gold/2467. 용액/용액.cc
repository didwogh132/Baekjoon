#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int arr[100010];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int left = 0;
    int right = n -1;
    int min = INT_MAX;
    int a = arr[left], b = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < min) {
            min = abs(sum);
            a = arr[left];
            b = arr[right];

        }

        if (sum < 0) left++;
        else right--;
    }

    cout << a << " " << b;

    return 0;
}