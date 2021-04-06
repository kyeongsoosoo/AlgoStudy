#include <stdio.h>

int A[100][100];
int B[100][100];

int main() {
    int N,M,K;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            scanf("%d", A[i]+j);
    }
    scanf("%d %d", &M, &K);
    for(int i=0; i<M; i++){
        for(int j=0; j<K; j++)
            scanf("%d", B[i]+j);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            int temp = 0;
            for(int c=0; c<M; c++){
                temp += A[i][c] * B[c][j];
            }
            printf("%d ", temp);
        }
        printf("\n");
    }
}