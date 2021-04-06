#include <stdio.h>
#include <string.h>

#define max(a,b) (a>b ? a : b)

char word1[1001];
char word2[1001];

int DP[1001][1001];

int main() {
    scanf("%s", word1);
    scanf("%s", word2);
    int length1 = strlen(word1);
    int length2 = strlen(word2);
    for(int i=0; i<=length1; i++)
        DP[i][0] = 0;
    for(int j=0; j<=length2; j++)
        DP[0][j] = 0;
    for(int i=1; i<=length1; i++){
        for(int j=1; j<= length2; j++){
            if(word1[i-1] == word2[j-1])
                DP[i][j] = DP[i-1][j-1] + 1;
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    }
    printf("%d", DP[length1][length2]);
}