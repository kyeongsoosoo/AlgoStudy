#include <stdio.h>
#define limit 10001


int counting[limit] = {0,};

int main() {
    int count, num;
    scanf("%d", &count);
    for(int i=1;i<=count;i++) {
        scanf("%d", &num);
        counting[num] += 1;
    }
    for(int i=1;i<=limit;i++){
        if(counting[i]==0) continue;
        int index=counting[i];
        for(int j=0;j<counting[i];j++){
            printf("%d\n", i);
        }
    }
    
}