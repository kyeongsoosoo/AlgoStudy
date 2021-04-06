#include <stdio.h>

long long distance[100000];
long long price[100000];

int main() {
    int caseN, index=0, std;
    long long min = 0;
    scanf("%d", &caseN);
    for(int i=0;i<caseN-1;i++){
        scanf("%lld", distance+i);
    }
    for(int i=0;i<caseN;i++){
        scanf("%lld", price+i);
    }
    
    while(index<caseN){
        std = index;
        for(int i=std+1;i<caseN;i++){
            min += price[std] * distance[i-1];
            if(price[std]<=price[i] || i == caseN-1){
                index++;
            }
            else{
                index = i;
                break;
            }
        }
        if(index+1 == caseN) break;
    }
    printf("%lld", min);
}
