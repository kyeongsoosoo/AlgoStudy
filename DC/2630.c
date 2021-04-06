#include <stdio.h>

int arr[128][128];
int whiteS = 0;
int blueS = 0;

void cutSquare(int length, int x, int y){
    if(length == 0) return;
    int first = arr[x][y];
    int isSquare =  1;
    int next = length/2;
    for(int i= x; i<x+length; i++){
        for(int j=y; j<y+length; j++){
            if(arr[i][j] != first){
                isSquare = 0;
                break;
            }
        }
    }
    if(isSquare){
        if(first == 0)
            whiteS += 1;
        else
            blueS += 1;
    }
    else {
        cutSquare(next, x, y);
        cutSquare(next, x+next,y);
        cutSquare(next, x, y+next);
        cutSquare(next, x+next, y+next);
    }
}

int main() {
    int leng;
    scanf("%d", &leng);
    for(int i=0; i<leng; i++){
        for(int j=0; j<leng; j++)
            scanf("%d", &arr[i][j]);
    }
    cutSquare(leng, 0, 0);
    printf("%d\n%d", whiteS, blueS);
}