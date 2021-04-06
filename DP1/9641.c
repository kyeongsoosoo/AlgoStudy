#include <stdio.h>

long long Pado[100] = {1,1,1,2,2,};

long long findP(int n){
    if(n<5)
        return Pado[n];
    else if(Pado[n]){
        return Pado[n];
    }
    else {
        return Pado[n] = findP(n-1) + findP(n-5);
    }

}

int main() {
    int testN;
    int PadoN;
    scanf("%d", &testN);
    for(int i=0; i<testN; i++){
        scanf("%d", &PadoN);
        long long a = findP(PadoN-1);
        printf("%lld\n", a);
    }
}