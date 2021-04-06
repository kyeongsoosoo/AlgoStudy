#include <stdio.h>

int moveCount=0;
int move[1100000][2];

void hannoi_move(int start, int mid, int end, int n){
    if(n == 0)
        return;
    hannoi_move(start,end,mid,n-1);
    move[moveCount][0] = start;
    move[moveCount++][1] = end;
    hannoi_move(mid,start,end,n-1);
}


int main() {
    int plateN;
    scanf("%d", &plateN);
    hannoi_move(1,2,3,plateN);
    printf("%d\n",moveCount);
    for(int i=0; i<moveCount; i++){
        printf("%d %d\n", move[i][0], move[i][1]);
    }
}