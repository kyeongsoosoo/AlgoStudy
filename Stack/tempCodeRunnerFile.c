#include <stdio.h>

int caseN;
int Stack[1000000];


int main() {
    scanf("%d", &caseN);
    int cursor = caseN-1;
    int index = 0;
    for(int i=0; i<caseN;i++)
        scanf("%d", Stack + i);
    for(int i=0;i<caseN-1;i++){
        for(int j=i; j<caseN;j++){
            if(Stack[j]> Stack[i]){
                printf("%d ", Stack[j]);
                break;
            }
        }
        if(Stack[i]>Stack[caseN-1])
            printf("-1 ");
    }
    printf("-1 ");
}