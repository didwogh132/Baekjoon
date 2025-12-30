#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<char, string> a;
    a['a'] = "aespa";
    a['b'] = "baekjoon";
    a['c'] = "cau";
    a['d'] = "debug";
    a['e'] = "edge";
    a['f'] = "firefox";
    a['g'] = "golang";
    a['h'] = "haegang";
    a['i'] = "iu";
    a['j'] = "java";
    a['k'] = "kotlin";
    a['l'] = "lol";
    a['m'] = "mips";
    a['n'] = "null";
    a['o'] = "os";
    a['p'] = "python";
    a['q'] = "query";
    a['r'] = "roka";
    a['s'] = "solvedac";
    a['t'] = "tod";
    a['u'] = "unix";
    a['v'] = "virus";
    a['w'] = "whale";
    a['x'] = "xcode";
    a['y'] = "yahoo";
    a['z'] = "zebra";
    string s;
    cin >> s;
    bool flag = true;
    int i = 0;
    vector<char> ans;
    while(i < s.size()&& flag) {
        int k = i;
        if (flag) {
            string b = a[s[i]];
            for (int j = 0; j < b.size(); j++) {
                if (b[j] == s[k++]) continue;
                else {
                    flag = false;
                    break;
                }
                k++;
            }
        }
        ans.push_back(s[i]);
        i = k;
    }
    if (flag) {
        cout << "It's HG!" << "\n";
        for (int i = 0; i < ans.size(); i++) cout << ans[i];
    }
    else {
        cout << "ERROR!";
    }
    return 0;
}