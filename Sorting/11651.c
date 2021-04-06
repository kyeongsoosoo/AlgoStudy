#include <stdio.h>

int testN;
int arrayX[100001]={0,};
int arrayY[100001]={0,};
int tempX[100001]={0,};
int tempY[100001]={0,};

void mergeSort(int start, int end, int middle){
    int s = start, m=middle;
    int count = start;
    while(s<=middle && m+1<=end){
        if(arrayY[s] <arrayY[m+1]){
            tempX[count]= arrayX[s];
            tempY[count++] = arrayY[s++];
        }
        else if(arrayY[s] > arrayY[m+1]){
            tempX[count] = arrayX[m+1];
            tempY[count++] = arrayY[(m++)+1];
        }
        else{
            if(arrayX[s] < arrayX[m+1]){
                tempX[count]= arrayX[s];
                tempY[count++] = arrayY[s++];
            }
            else if(arrayX[s] > arrayX[m+1]){
                tempX[count] = arrayX[m+1];
                tempY[count++] = arrayY[(m++)+1];
            }
        }
        
    }
    while(s<=middle){
            tempX[count]= arrayX[s];
            tempY[count++] = arrayY[s++];
            
        }
    while(m+1<=end){
            tempX[count] = arrayX[m+1];
            tempY[count++] = arrayY[(m++)+1];
            
        }
    for(int i=start; i<=end; i++){
            arrayX[i]=tempX[i];
            arrayY[i]=tempY[i];
        }
    
}


void merge(int start, int end){
    if(start <end){
        int middle = (start+end)/2;
        merge(start,middle);
        merge(middle+1, end);
        mergeSort(start,end, middle);

    }
}

int main() {
    int a=0;
    scanf("%d", &testN);
    for(int i=0;i<testN;i++){
        scanf("%d %d", arrayX+i,arrayY+i);
    }
    merge(0, testN-1);
    for(int i=0; i<testN; i++){
        printf("%d %d\n", arrayX[i],arrayY[i]);
    }

}