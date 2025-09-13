#include <stdio.h>
int main() {
    unsigned int p=0;
    for(int i=0,x;i<8;i++){scanf("%d",&x);p=(p<<3)|(x-1);}
    if(p==0x53977) puts("ascending");
    else if(p==0xFAC688) puts("descending");
    else puts("mixed");
}