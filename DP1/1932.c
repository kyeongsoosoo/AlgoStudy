#include <stdio.h>
#define f_max(a,b) ((a>b) ? a : b)

int org[500][500];
int max[500][500];
int N;
int given;
int count=-1;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            scanf("%d", &given);
            if(i==0)
               { max[i][j] = given;}
            else if(j==0){
                max[i][j] = max[i-1][j] + given;
            }
            else if(j==i){
                max[i][j] = max[i-1][j-1] + given;
            }
            else{
                max[i][j] = f_max(max[i-1][j-1], max[i-1][j]) + given;
            }
            if(i==N-1){
                if(max[i][j] >count)
                    count = max[i][j];             
            }

        }
    }
    printf("%d\n", count);   
}