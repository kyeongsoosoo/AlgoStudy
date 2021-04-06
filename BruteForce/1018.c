#include <stdio.h>

int main() {
    int row,col;
    scanf("%d %d", &row, &col);
    char board[row][col];
    int caseW, caseB, min=65;


    for(int i=0; i<row; i++){
        scanf("%s", board[i]);
    }
    for(int i=0; i<row-7; i++){
        for(int j=0; j<col-7; j++){
            caseW=0;
            caseB=0;
            for(int p=i; p<i+8; p++){
                for(int q=j; q<j+8; q++){
                    
                        if((p+q-i-j)%2 ==0){
                            if(board[p][q]=='B') caseW++;
                            else caseB++;
                        }
                        else{
                            if(board[p][q]=='B') caseB++;
                            else caseW++;
                        }
                    }
                    
                }
            min = min < caseW ? min : caseW;
            min = min < caseB ? min : caseB;
            }
            
        }
        printf("%d", min);
}
    