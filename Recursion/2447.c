#include <stdio.h>

int star_box[2200][2200];

void decide_empty(int x_cord, int y_cord, int n){
    int div;
    if(n==1){
        star_box[y_cord][x_cord] = 1;
        return;
    } 
    div = n/3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==1 && j==1){
                continue;
            }
            else 
                decide_empty(x_cord+(div*j),y_cord+(div*i),div);
        }
    }
}


int main() {
    int num;
    scanf("%d", &num);
    decide_empty(0,0,num);
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            if(star_box[i][j] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}
