#include <stdio.h>

int main() {
    int t_case[20000];
    int index =0;
    int example;

    t_case[index++] =1;
    while(1){
        t_case[index] = t_case[index-1] + (6*index);
        if(t_case[index]>1000000000) break;
        index++;
    }
    scanf("%d", &example);
    int length = sizeof(t_case)/4;
    for(int i=0; i<length; i++){
        if(i>0 && t_case[i-1]<example && example<=t_case[i]) {
            printf("%d", i+1);
            break;
        }
        else if(t_case[0] == example){
            printf("1");
            break;
        }
    }
}


