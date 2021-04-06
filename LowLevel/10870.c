#include <stdio.h>

int fibonacciN(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibonacciN(n-1) + fibonacciN(n-2);

}

int main() {
    int testN;
    scanf("%d", &testN);
    printf("%d", fibonacciN(testN));
}