#include <stdio.h>

int sumN(int n) {
    int sum = n;
    while(n != 0 ){
        sum += (n%10);
        n = n/10;
    }
    return sum;
}

int main() {
    int testN, result=0;
    scanf("%d", &testN);
    
    for(int i=1; i<testN; i++){
        if(sumN(i) == testN) {
            result = i;
            break;
        }   
    }
    printf("%d\n", result);

}