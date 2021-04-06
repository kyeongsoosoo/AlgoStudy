#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

char result[MAX*2];
int stack[MAX];
int top = -1;
int caseN;
int num = 1, idx=0, resultIndex = 0;

int main() {
    int caseN;
    scanf("%d", &caseN);

    int* arr = (int*)malloc(sizeof(int)*caseN);
    for(int i=0; i<caseN; i++)
        scanf("%d", &arr[i]);
    while(1){
        if(top==-1 || stack[top]<arr[idx]){
            stack[++top] = num++;
            result[resultIndex++] = '+';
        }
        else if(stack[top] == arr[idx]){
            top--;
            result[resultIndex++] = '-';
            idx++;
        }
        else {
            printf("NO\n");
            return 0;
        }
        if (resultIndex == caseN*2) break;
    }
    for(int i=0;i<resultIndex;i++)
        printf("%c\n", result[i]);
}