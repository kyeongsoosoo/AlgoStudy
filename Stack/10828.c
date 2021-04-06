#include <stdio.h>
#include <string.h>


int Stack[10000];
int cursor = 0;
int num;
char order[10];

int main() {
    int caseN;
    scanf("%d", &caseN);
    for(int i=0; i<caseN; i++){
        scanf("%s", order);
        if(!strcmp(order,"push")){
            scanf("%d", &num);
            Stack[cursor++] = num;
        
        }
        else if(!strcmp(order,"pop")){
            if(!cursor) printf("-1\n");
            else printf("%d\n", Stack[--cursor]);
        }
        else if(!strcmp(order,"top")){
            if(!cursor) printf("-1\n");
            else printf("%d\n", Stack[cursor-1]);
        }
        else if(!strcmp(order,"empty")){
            if(!cursor) printf("1\n");
            else printf("0\n");
        }
        else printf("%d\n", cursor);
    }
}