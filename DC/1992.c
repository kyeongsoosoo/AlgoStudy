#include <stdio.h>

char arr[65][65];
char tree[20000];
int idx = 0;

void cutSquare(int length, int x, int y){
    if(length == 0) return;
    char first = arr[y][x];
    int halfLeng = length/2;
    int isSquare = 1;
    for(int i=y; i<y+length; i++){
        for(int j=x; j<x+length; j++){
            if(arr[i][j] != first){
                isSquare = 0;
                break;
            }
        }
    }
    if(isSquare){
        tree[idx++] = first;
        return;
    }
    else {
        tree[idx++] = '(';
        cutSquare( halfLeng, x, y);
        cutSquare( halfLeng, x+halfLeng, y);
        cutSquare( halfLeng, x, y+halfLeng);
        cutSquare( halfLeng, x+halfLeng, y+halfLeng);
        tree[idx++] = ')';
    }
}

int main() {
    int leng;
    scanf("%d", &leng);
    for(int i=0; i<leng; i++){
        scanf("%s", arr[i]);
    }
    cutSquare(leng, 0, 0);
    int id = 0;
    while(tree[id] != '\0'){
        printf("%c", tree[id++]);
    }
}