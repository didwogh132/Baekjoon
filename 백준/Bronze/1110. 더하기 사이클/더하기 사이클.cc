#include <iostream>
using namespace std;
 
int main() {
    int N;
    cin >> N;
 
    int origin = N;
    int result = -1;
    int u, t, s;
    int cnt = 0;
 
    while (result != origin) {
        if (N < 10) {
            u = N;
            t = 0;
        }
        else {
            u = N % 10;
            t = N / 10;
        }
        
        s = u + t;
        s = s % 10;
 
        result = u * 10 + s;
 
        N = result;
 
        cnt++;
    }
    
    cout << cnt;
}