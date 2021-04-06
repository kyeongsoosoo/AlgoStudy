#include <stdio.h>
#define limit 1000000000

int arr[100][10] = {{1,1,1,1,1,1,1,1,1,1},};

int main() {
    int rangeN;
    int sum=0;
    scanf("%d", &rangeN);
    for(int i=1; i<rangeN; i++){
        for(int j=0; j<=9; j++){
            if( j == 9)
                arr[i][j] = arr[i-1][j-1]%limit;
            else if(j==0)
                arr[i][j] = arr[i-1][j+1]%limit;
            else
                arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1])%limit;
            if(i == rangeN-1 && j>0)
                sum += arr[i][j];
                sum %= limit;
        }
    }
    printf("%d", (rangeN>1) ? sum : 9);
}