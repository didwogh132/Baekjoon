#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace algo {
    namespace ps {
        class LIS {
        private:
            vector<int> arr;
            vector<int> lis;
        public:
            LIS(int n) {
                arr.resize(n);
            }

            void init(int idx, int num) {
                arr[idx] = num;
            }

            void find() {
                for (int i = 0; i < arr.size(); i++) {
                    int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
                    if (lis.empty() || idx >= lis.size()) {
                        lis.push_back(arr[i]);
                    }
                    else {
                        lis[idx] = arr[i];
                    }
                }
            }
            int size() {
                return lis.size();
            }
        };
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    algo::ps::LIS lis(n);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        lis.init(i, num);
    }

    lis.find();

    cout << lis.size();
    return 0;
}