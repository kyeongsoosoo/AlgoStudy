#include <stdio.h>

int main() {
    int count, litmit;
    int numberSet[100];
    int max = 0;
    scanf("%d %d", &count, &litmit);
    for(int i =0; i<count; i++){
        scanf("%d", numberSet+i);
    }
    for(int i=0; i<count-2; i++){
        for(int j=i+1; j<count-1; j++){
            for(int p=j+1; p<count; p++){
                int tester = numberSet[i] + numberSet[j]+numberSet[p];
                if(tester <=litmit && max<tester){
                    max = numberSet[i]+numberSet[j]+numberSet[p];
                }
            }
        }
    }
    printf("%d", max);
}