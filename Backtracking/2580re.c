#include <stdio.h>

int KU[9][9];
int Empty[81][2];
int length = 0;
int DONE = 0;




int promising(int level, int num){
    int y_cord = Empty[level][0];
    int x_cord = Empty[level][1];
    int x_box_cord;
    int y_box_cord;
    for(int i=0; i<9; i++){
        //수평라인 체크
        if(KU[y_cord][i] == num) return 0;
        //수직라인 체크
        if(KU[i][x_cord] == num) return 0;
    }
    x_box_cord = (x_cord/3)*3;
    y_box_cord = (y_cord/3)*3;

    for(int i=y_box_cord; i<y_box_cord+3; i++){
        for(int j= x_box_cord; j<x_box_cord+3; j++){
            if(KU[i][j] == num) return 0;
        }
    }
    return 1;

}

void sudoku(int level, int num){
    int y_cord = Empty[level][0];
    int x_cord = Empty[level][1];
    if(!promising(level, num)) return;
    if(level+1 == length){
        KU[y_cord][x_cord] = num;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                printf("%d ", KU[i][j]);
        }
        printf("\n");
        }
        DONE = 1;
        return;
    }
    if(DONE == 1) return;

    for(int i=1; i<10; i++){
        KU[y_cord][x_cord] = num;
        sudoku(level+1, i);
        KU[y_cord][x_cord] = 0;
    
    }
    return;
}


int main() {
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            scanf("%d", &KU[i][j]);
            if(KU[i][j] == 0 ){
                Empty[length][0] = i;
                Empty[length++][1] = j;}
        }
    }
    for(int i=1; i<10; i++)
       { sudoku(0, i);}

}