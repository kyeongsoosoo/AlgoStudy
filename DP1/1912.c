#include <stdio.h>

int num[100000];
int DP[100000];

int main() {
    int testN;
    int maxN = -2000;
    scanf("%d", &testN);
    for(int i=0; i<testN; i++){
        scanf("%d", num+i);
    }
    DP[0] = num[0];
    for(int i=1; i<testN; i++){
        if(num[i] > 0 ){
            if(DP[i-1] < 0)
                DP[i] = num[i];
            else 
                DP[i] = DP[i-1] + num[i];
        }
        else {
            if(DP[i-1] + num[i] > 0)
                DP[i] = DP[i-1] + num[i];
            else
                DP[i] = num[i];
        }
    }
    for(int i=0; i<testN; i++){
        if(DP[i] > maxN)
            maxN = DP[i];
    }
    printf("%d", maxN);
}