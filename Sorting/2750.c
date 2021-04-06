#include <stdio.h>

int main() {
    int count;
    scanf("%d", &count);
    int array[count];
    for (int i=0; i<count;i++) scanf("%d", array+i);
    
    int temp = 0;
    for(int i=count-1; i>0;i--){
        for(int j=0;j<i;j++){
            if(array[j]>array[j+1]) {
                temp=array[j+1];
                array[j+1]=array[j];
                array[j]=temp;
            }
        }
    }
    for(int i=0;i<count;i++){
        printf("%d\n",array[i]);
    }
}