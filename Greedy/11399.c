#include <stdio.h>

int time[1000];
int caseN;

int main() {
    
    scanf("%d", &caseN);
    for(int i=0;i<caseN;i++){
        scanf("%d", time+i);
    }
    int index=caseN-1;
    while(index){
        for(int i=0;i<index;i++){
            if(time[i]>time[i+1]){
                int temp = time[i+1];
                time[i+1] = time[i];
                time[i] = temp;
            }
        }
        index--;
    }
    int sum=0;
    for(int i=0;i<caseN;i++){
        sum += time[i]*(caseN-i); 
    }
    printf("%d\n", sum);


}