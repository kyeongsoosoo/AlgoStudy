#include <stdio.h>

int count;
int array[1000000];

void merge(int start, int middle, int end){
    int temp[end-start+1];
    int i=start, p=middle+1, index=start;
    while(i<=middle && p<=end){
        if(array[i]<=array[p]) temp[index++]=array[i++];
        else temp[index++]=array[p++];
    }
    while(i<=middle){
        temp[index++]=array[i++];
    }
    while(p<=end){
        temp[index++]=array[p++];
    }
    for(int i=start; i<=end; i++){
        array[i] = temp[i];
    }
}

void mergeSort(int start, int end){
    if(start<end) {
        int middle = (start+end)/2;
        mergeSort(start,middle);
        mergeSort(middle+1,end);
        merge(start,middle,end);
    }
}

int main() {
    
    scanf("%d", &count);
    
    for(int i=0; i<count; i++) scanf("%d", array+i);
    mergeSort(0,count-1);
    for(int i=0; i<count; i++) printf("%d\n", array[i]);

}