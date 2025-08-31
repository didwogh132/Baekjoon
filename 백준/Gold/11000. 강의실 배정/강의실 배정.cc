#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    long long start;
    long long end;
};
struct room {
    long long end;
    bool operator <(room right) const {
        if (end > right.end) return true;
        if (end < right.end) return false;
        return false;
    }
};
vector<node> arr;
priority_queue<room> pq;

bool cmp(node a, node b) {
    if (a.start < b.start) return true;
    if (a.start > b.start) return false;
    return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long end, start;
        cin >> start >> end;
        arr.push_back({ start, end });
    }
    sort(arr.begin(), arr.end(), cmp);

    pq.push({ arr[0].end });

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= pq.top().end) {
            pq.pop();
        }
        pq.push({ arr[i].end });
    }

    cout << pq.size();
    return 0;
}