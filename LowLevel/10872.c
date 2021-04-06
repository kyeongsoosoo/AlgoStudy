#include <stdio.h>

int factorialN(int n){
    if(n<=1) return 1;
    return n*factorialN(n-1);
}

int main() {
    int testN;
    scanf("%d", &testN);
    int result = factorialN(testN);
    printf("%d", result);
    
}