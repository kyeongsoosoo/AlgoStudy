#include <stdio.h>
#include <stdbool.h>

int mainBoard[9][9];
int count=0;
int zeroCord[100][2];



bool Check(int number, int level){
    int XCord = zeroCord[level][0];
    int YCord = zeroCord[level][1];
    for(int i=0; i<9; i++){
        //vertical
        
        
        
        if (mainBoard[i][XCord] == number ) {
        
            return false;}
        //horizontal
        if (mainBoard[YCord][i] == number ) {
        
            return false;}
    }
    for(int i=(YCord/3)*3; i<(YCord/3)*3+3; i++){
        for(int j=(XCord/3)*3; j<(XCord/3)*3+3; j++){
            if(mainBoard[i][j] == number) {
                
                
        
                
                return false;}
        }
    }
    return true;
}

void sudoku(int number, int level){
    if( !Check(number,level) ) return;
    
    
    if(level+1 == count) {
         mainBoard[zeroCord[level][1]][zeroCord[level][0]] = number;
        for(int i=0; i<9; i++){
            for(int j=0;j<9; j++){
                printf("%d ", mainBoard[i][j]);
            }
            printf("\n");
        }
        return;
    }
    for(int i=1; i<10; i++){
        mainBoard[zeroCord[level][1]][zeroCord[level][0]] = number;
        
        sudoku(i, level+1);
        mainBoard[zeroCord[level][1]][zeroCord[level][0]] = 0;
    }
    return;
}


int main() {
    
    for(int i=0;i<9; i++){
        for(int j=0;j<9;j++){
            scanf("%d" ,&mainBoard[i][j]);
            if(mainBoard[i][j] == 0){
                zeroCord[count][0]=j;
                zeroCord[count++][1]=i;
            }
        }
    }
    for(int i=1; i<10;i++){
        sudoku(i,0);
        
    }
}