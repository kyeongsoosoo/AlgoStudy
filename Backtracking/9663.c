#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int board[15] = {0,};
int count = 0;

bool isPromising(int level, int position){
    if(level >0) {
        for(int i=0; i<level; i++){
            if(board[i] == position) return false;
            else if(level - i == abs(position-board[i])) {

                return false;}
    }
    }
    return true;
}


void nQueen(int level, int boardSize, int position){

     

    if(!isPromising(level, position) ) {
        return;
    }

    if(level+1 == boardSize) {
        count++;
        return;
    }
   
    
    for(int i=0; i<boardSize; i++){
        board[level] = position; 
        nQueen(level+1, boardSize, i);
    }
    return;
}

int main() {
    int boardSize;
    scanf("%d", &boardSize);
    for(int i=0; i<boardSize; i++){
        nQueen(0,boardSize,i);

    }
    printf("%d", count);
}