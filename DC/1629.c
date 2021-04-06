#include <stdio.h>

int A,B,C;

long long calc(int A, int B ){
    if (B == 0) return 1;

    long long tmp = calc(A, B/2);

    if(B % 2)
        return ((tmp * tmp) % C) * A % C;
    else 
        return (tmp * tmp) % C;
}

int main() {
    scanf("%d %d %d", &A, &B, &C);
    long long result = calc(A,B);
    printf("%lld", result);
}


