#include <stdio.h>

int arr[2500][2500];

int counter[3] ={0,};

void cutSquare(int leng, int x, int y){
    if(leng == 0) return;
    int isSqure = 1;
    int cut = leng/3;
    int first = arr[y][x];
    for(int i=y; i<y+leng; i++){
        for(int j=x; j<x+leng; j++){
            if(first != arr[i][j]){
                isSqure = 0;
                break;
            }
        }
    }
    if(isSqure){
        counter[first+1] += 1;
    }
    else{
        cutSquare( cut, x, y);
        cutSquare( cut, x+cut, y);
        cutSquare( cut, x, y+cut);
        cutSquare( cut, x+cut, y+cut);
        cutSquare( cut, x+(cut*2), y);
        cutSquare( cut, x, y+(cut*2));
        cutSquare( cut, x+cut, y+(cut*2));
        cutSquare( cut, x+(cut*2), y+cut);
        cutSquare( cut, x+(cut*2), y+(cut*2));
    }
}

int main() {
    int leng;
    scanf("%d", &leng);
    for(int i=0; i<leng; i++){
        for(int j=0; j<leng; j++)
            scanf("%d", arr[i] + j);
    }
    cutSquare(leng, 0,0);
    printf("%d\n%d\n%d", counter[0], counter[1], counter[2]);

}