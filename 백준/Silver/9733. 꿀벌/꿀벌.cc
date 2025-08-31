#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    vector<string> order = { "Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex", "Total" };
    map<string, int> dict;
    string num;
    for (int i = 0; i < order.size(); i++) {
        string s = order[i];
        dict[s] = 0;
    }
    while (cin >> num) {
        if (dict.find(num) != dict.end()) {
            dict[num]++;
            dict["Total"]++;
        }
        else {
            dict["Total"]++;
        }
    }

    cout << fixed;
    cout.precision(2);

    for (int i = 0; i < order.size(); i++) {
        string s = order[i];
        if (s != "Total") {
            cout << s << " " << dict[s] << " " << (double)dict[s] / dict["Total"] << "\n";
        }
    }
    cout << "Total " << dict["Total"] << " 1.00" << "\n";

    return 0;
}
