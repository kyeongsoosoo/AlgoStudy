#include <stdio.h>

int X;
long long T;

long long ex[5][5];
long long temp[5][5];
long long result[5][5];

void multiply(long long A[5][5], long long B[5][5]){
    for(int i=0;i<X; i++){
        for(int j=0; j<X; j++){
            temp[i][j] = 0;
            for(int k=0; k< X; k++)
                temp[i][j] += (A[i][k] * B[k][j]);
            temp[i][j] %= 1000;
        }
    }
    for(int i=0; i< X; i++)
        for(int j=0; j<X; j++)
           A[i][j] = temp[i][j];
}

int main() {
    scanf("%d %lld", &X, &T);
    for(int i=0; i<X; i++){
        for(int j=0; j<X; j++)
            scanf("%lld", ex[i]+j);
        result[i][i] = 1;
    }
    while(T != 0){
        if(T%2){
            multiply(result, ex);
        }
        multiply(ex,ex);
        T /= 2;
    }
    for(int i=0; i<X; i++){
        for(int j=0; j<X; j++)
            printf("%lld ", result[i][j]%1000);
        printf("\n");
    }
}