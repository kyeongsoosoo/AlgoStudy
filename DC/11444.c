#include <stdio.h>
#include <stdlib.h>
#define divN 1000000007

long long ans[2][2] = {{1,0},{0,1}};
long long A[2][2] = {{1,1},{1,0}};
long long temp[2][2];

void pow_F(long long A[2][2], long long B[2][2]){
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            temp[i][j] = 0;
            for(int k=0; k<2; k++){
                temp[i][j] += A[i][k] * B[k][j];
            }
            temp[i][j] %= divN;
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++)
            A[i][j] = temp[i][j];
    }
}


int main() {
   
    long long L;
    scanf("%lld", &L);

    while(L>0){ 
        if(L%2)
            pow_F(ans, A);
        pow_F(A,A);
        L /= 2;
    }
    printf("%lld\n", ans[0][1]%divN);
}