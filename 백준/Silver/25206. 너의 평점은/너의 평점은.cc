#include <iostream>
#include <string.h>

using namespace std;

struct node {
    string sub;
    float point;
    string score;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    node arr[21];

    float total_sum = 0;
    float total_cnt = 0;
    float ans = 0;

    for (int i = 0; i < 20; i++) {
        cin >> arr[i].sub >> arr[i].point >> arr[i].score;
        if (arr[i].score == "P") continue;
        else if (arr[i].score == "F") {
            total_cnt += arr[i].point;
        }
        else if (arr[i].score == "A+") {
            total_sum += arr[i].point * 4.5;
            total_cnt += arr[i].point;
        }
        else if (arr[i].score == "A0") {
            total_sum += arr[i].point * 4.0;
            total_cnt += arr[i].point;
        }
        else if (arr[i].score == "B+") {
            total_sum += arr[i].point * 3.5;
            total_cnt += arr[i].point;
        }
        else if (arr[i].score == "B0") {
            total_sum += arr[i].point * 3.0;
            total_cnt += arr[i].point;
        }
        else if (arr[i].score == "C+") {
            total_sum += arr[i].point * 2.5;
            total_cnt += arr[i].point;
        }
        else if (arr[i].score == "C0") {
            total_sum += arr[i].point * 2.0;
            total_cnt += arr[i].point;
        }
        else if (arr[i].score == "D+") {
            total_sum += arr[i].point * 1.5;
            total_cnt += arr[i].point;
        }
        else if (arr[i].score == "D0") {
            total_sum += arr[i].point * 1.0;
            total_cnt += arr[i].point;
        }
    }

    ans = total_sum / total_cnt;

    cout << ans;

    return 0;
}