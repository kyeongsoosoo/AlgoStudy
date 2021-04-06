#include <stdio.h>

int main() {
    int N,K;
    scanf("%d %d", &N, &K);
    int num[N], index=N-1, count =0;
    for(int i=0;i<N;i++){
        scanf("%d", num+i);
    }
    for(int i=N-1; i>=0; i--){
        count += K/num[i];
        K %= num[i];
    }
    printf("%d", count);
}