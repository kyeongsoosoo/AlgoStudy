#include <stdio.h> 

void checkNum(int x, int y, int testSize){
    if ((x/testSize) % 3 == 1 && (y / testSize) % 3 == 1 ){
        printf(" ");
    } else {
        if(testSize / 3 == 0) {
            printf("*");
        } else{
            checkNum(x, y, testSize/3);
        }
    }
}

int main() {
    int testSize;
    scanf("%d", &testSize);
    for(int i=0; i<testSize; ++i){
        for(int j=0; j<testSize; ++j){
            checkNum(i,j,testSize);
        }
        printf("\n");
    }
}