#include <stdio.h>
#define f_max(a,b) ((a>b) ? a : b)

int step[300][3];
//[0] 두칸 다 밟는 경우
//[1] 한칸만 밟는 경우
//[2] 안밟는경우

int main() {
    int stairN;
    int score;
    int final;
    scanf("%d",&stairN);
    scanf("%d", &score);
    step[0][0] = final = score;
    step[0][1] = score;
    step[0][2] = 0;
    for(int i=1; i<stairN; i++){
        scanf("%d", &score);
        if(i == stairN-1){
            final = f_max(step[i-1][1], step[i-1][2]) + score;
        }
        else {
            step[i][0] = step[i-1][1] + score;
            step[i][1] = step[i-1][2] + score;
            step[i][2] = f_max(step[i-1][0], step[i-1][1]);
        }
    }
    printf("%d", final);

}