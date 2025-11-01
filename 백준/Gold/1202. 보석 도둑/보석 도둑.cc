#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
struct node {
    int weight;
    int value;
    bool operator <(const node& right) {
        if (weight != right.weight) return weight < right.weight;
        return value > right.value;
    }
};
vector<node> arr;
vector<int> bag;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;
        arr.push_back({ weight, value });
    }

    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        bag.push_back(num);
    }
    sort(arr.begin(), arr.end());
    sort(bag.begin(), bag.end());

    int j = 0;
    long long ans = 0;

    for (int i = 0; i < k; i++) {
        while (j < n && arr[j].weight <= bag[i]) {
            pq.push(arr[j].value);
            j++;
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}