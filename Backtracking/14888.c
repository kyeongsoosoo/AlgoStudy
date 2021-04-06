#include <stdio.h>
#include <stdlib.h>

int min = 1000000000;
int max = -1000000000;


int testN;
int numArray[100];
int oepPerm[99];
int opeArray[4]; 


void swapArray(int start, int target){

    int temp = oepPerm[start];
    oepPerm[start] = oepPerm[target];
    oepPerm[target]=temp;
}

int calcArray(int index, int calcNum){
    switch (oepPerm[index])
    {
    case 0:
        calcNum += numArray[index+1];
        return calcNum;
    
    case 1:
        calcNum -= numArray[index+1];
        return calcNum;
    
    case 2:
        calcNum *= numArray[index+1];
        return calcNum;
    
    case 3:
        calcNum /= numArray[index+1];
        return calcNum;
    
    default:
        return 0;
    }
}

void makeN(int index, int calcNum){
    if(index+1 == testN-1){
        int calc = calcArray(index,calcNum);
        if(calc>max) max=calc;
        if(calc<min) min=calc;
        
    }
    for(int i=index; i<testN-1;i++){
        swapArray(index, i);
        int calc = calcArray(index,calcNum);
        
        makeN(index+1, calc);
        swapArray(i, index);
    }
}


int main() {
    
    scanf("%d", &testN);
    
    for(int i =0; i<testN; i++){
        scanf("%d", numArray+i);
    }
    for(int i=0;i<4; i++){
        scanf("%d", opeArray+i);
    }


    int permIndex=0;
    for(int i=0;i<4;i++){
        while(opeArray[i]>0){
            oepPerm[permIndex++]= i;
            opeArray[i]--;
        }
    }
    makeN(0,numArray[0]);
    printf("%d\n%d", max, min);
    


}