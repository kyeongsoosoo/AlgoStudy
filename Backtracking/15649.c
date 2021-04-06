#include <stdio.h>

int testArray[8];

void test(int start, int depth, int number, int length) {
    testArray[depth] = start;
    if(depth>0){
        for(int i=0; i<depth; i++){
            
            if(start < testArray[i]) return;


        }
    }
    if(depth+1 == length) {
        for(int i=0; i<length; i++) printf("%d ", testArray[i]+1);
        printf("\n");
        return;
    };
    for(int i=0; i< number; i++){
        
        test(i, depth+1, number,length);
    }
}


int main() {
    int number, length;
    scanf("%d %d", &number, &length);
    for(int i=0; i<number; i++){

    test(i,0,number, length);
    }
}