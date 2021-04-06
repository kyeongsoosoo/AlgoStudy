#include <stdio.h>
#define max(a,b) (a>=b ? a : b)

int val[100];
int w[100];

int DP[100001][101];

int main() {
    int limitN, limitW;
    scanf("%d %d", &limitN, &limitW);
    for(int i=0; i<limitN; i++){
        scanf("%d %d", w+i, val+i);
    }
    for(int i=0; i<=limitW; i++){
        for(int j=0; j<=limitN; j++){
            if(i==0 || j == 0)
                DP[i][j] = 0;
            else if( i< w[j-1])
                DP[i][j] = DP[i][j-1];
            else
                DP[i][j] = max(DP[i][j-1], (val[j-1] + DP[i-w[j-1]][j-1]));
        }
    }
    printf("%d", DP[limitW][limitN]);
}