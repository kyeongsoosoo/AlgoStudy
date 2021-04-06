#include <stdio.h>
#include <stdlib.h>
#define square_N 100000
#define max(a,b) ((a>b) ? a : b)


long long DP[square_N][square_N][3];

int main() {
    
    int num;
    long long result;
    while(1){
        result = 0;
        scanf("%d", &num);
        long long *test = malloc(sizeof(long long) * num);
        if(!num) {
            free(test);
            break;
            }
        for(int i=0; i<num; i++)
            scanf("%lld", test + i);
        for(int i=0; i<num; i++){
            for(int j=i; j>=0; j--){
                if(i==j) {
                    DP[i][j][0] = test[i];
                    DP[i][j][1] = 1;
                }
                else if(DP[i][i][0]>=DP[i-1][i-1][0]){
                    DP[i][j][0] = DP[i-1][j][0];
                    DP[i][j][1] = DP[i-1][j][1] + 1; 
                }
                else{
                    DP[i][j][0] = DP[i][i][0];
                    DP[i][j][1] = DP[i-1][j][1] + 1;
                }
                DP[i][j][2] = DP[i][j][0] * DP[i][j][1];
            }
        }
        for(int i=0; i<num; i++){
            for(int j=i; j>=0; j--){
                result = max(result, DP[i][j][2]);
            }
        }
        printf("%lld\n", result);
        free(test);
    }
}