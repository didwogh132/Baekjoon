#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace algo {
    namespace ds {
        class LIS {
        private:
            vector<int> arr;
            vector<int> lis;
            vector<int> lis_idx;
        public:
            void setArray(const vector<int>& input) {
                arr = input;
                lis.clear();
                lis_idx.clear();
                lis_idx.resize(arr.size(), 0);
            }

            void build() {
                int n = arr.size();
                lis.reserve(n);

                for (int i = 0; i < n; i++) {
                    int x = arr[i];

                    if (lis.empty() || lis[lis.size() - 1] < x) {
                        lis.push_back(x);
                        lis_idx[i] = lis.size();
                    }
                    else {
                        int idx = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
                        lis[idx] = x;
                        lis_idx[i] = idx + 1;
                    }
                }
            }
            int length() const {
                return lis.size();
            }

            vector<int> trace() const{
                int n = arr.size();
                int need = lis.size();
                vector<int> path;
                path.reserve(lis.size());

                for (int i = n - 1; i >= 0; i--) {
                    if (lis.size() == 0) break;

                    if (lis_idx[i] == need) {
                        path.push_back(i + 1);
                        need--;
                    }
                }

                reverse(path.begin(), path.end());

                return path;
            }
        };
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) cin >> a[i];

        algo::ds::LIS lis;

        lis.setArray(a);
        lis.build();

        cout << lis.length() << "\n";

        vector<int> path = lis.trace();
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}