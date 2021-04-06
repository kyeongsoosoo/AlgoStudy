#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int caseN;
int arr[1000000];
int Stack[1000000];
int ans[1000000];


int main() {
    scanf("%d", &caseN);
    memset(ans, -1, sizeof(ans));
    int top = 0;

    for(int i=0; i<caseN;i++)
        scanf("%d", arr + i);

    Stack[0] = 0;

    for(int i= 1; i< caseN; i++){
        if(top == -1) {
            Stack[++top] = i;
        }
        else if(arr[Stack[top]] >= arr[i]){
            Stack[++top] = i;
        }
        else if(arr[Stack[top]] < arr[i]){
            while(top > -1){
                if(arr[Stack[top]] >= arr[i]) {
                    Stack[++top] = i;
                    break;
                }
                ans[Stack[top]] = arr[i];

                top--;
            }
            Stack[++top] = i;
        }
    }
    for(int i=0; i<caseN-1; i++){
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[caseN-1]);
}