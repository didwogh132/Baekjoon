#include <iostream>
#include <string>

using namespace std;

int n;
string name;
int ydir[] = { 1, 0, -1, 0 };
int xdir[] = { 0, 1, 0, -1 };
int arr[110][110];
int sy = 55, sx = 55;

int main() {
    
    cin >> n >> name;

    int order_num = 0;
    int ymin = 55;
    int xmin = 55;
    int ymax = 55;
    int xmax = 55;
    arr[sy][sx] = 1;
    for (int i = 0; i < name.size(); i++) {
        if (name[i] == 'R') {
            order_num = (order_num + 3) % 4;
        }
        else if (name[i] == 'L') {
            order_num = (order_num + 1) % 4;
        }
        else {
            sy += ydir[order_num];
            sx += xdir[order_num];
            if (sy < ymin) {
                ymin = sy;
            }
            if (sy > ymax) {
                ymax = sy;
            }
            if (sx < xmin) {
                xmin = sx;
            }
            if (sx > xmax) {
                xmax = sx;
            }
            arr[sy][sx] = 1;
        }
    }
    for (int i = ymin; i <= ymax; i++) {
        for (int j = xmin; j <= xmax; j++) {
            if (arr[i][j] == 0) {
                cout << "#";
            }
            else {
                cout << ".";
            }
        }
        cout << "\n";
    }
    return 0;
}