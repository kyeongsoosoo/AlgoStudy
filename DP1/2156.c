#include <stdio.h>
#define max(a,b) (a>b) ? a : b 

int glass[10001]={0,};
int DP[10001] ={0,};


int main(){
    int testN;
    scanf("%d", &testN);
    for(int i=0; i<testN; i++){
        scanf("%d", glass+i);
    }
    DP[1] = glass[0];
    DP[2] = DP[1] + glass[1];
    for(int i=3; i<=testN; i++){
        
        DP[i] = max(DP[i-2]+glass[i-1], (max(DP[i-3]+glass[i-2]+glass[i-1], DP[i-1])));
    }
    printf("%d", DP[testN]);
}
