#include <stdio.h>
#include <math.h>


void hannoi(int n, int start, int temp, int end){
    
    if(n == 1) printf("%d %d\n", start, end);
    else {
        hannoi(n-1, start, end, temp);
        printf("%d %d\n", start, end);
        hannoi(n-1, temp, start, end);
    }
}


int main() {
    int plateN;
    scanf("%d", &plateN);
    printf("%.0f\n", pow(2, plateN) - 1);
    hannoi(plateN, 1,2,3);
    
}