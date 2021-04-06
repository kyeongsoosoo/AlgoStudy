#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 101

char str[MAX];
int stack[MAX];
int cursor = 0;
int len=0;
bool isTrue;;

void checkP(char* P){
    len = strlen(P);
    isTrue = true;
    cursor = 0;
    for(int i=0; i<len; i++){
        
        if(P[i] == '(' || P[i] == '['){
            stack[cursor++] = P[i];
        }
        if(P[i] == ')' || P[i] == ']'){
            if(cursor ==0) {
                isTrue = false;
                break;
            }
            if(P[i] == ')'){
                if(stack[cursor-1] == '(')
                    cursor--;
                else if(stack[cursor-1] == '['){
                    isTrue = false;
                    break;
                }
            }
            if(P[i] == ']'){
                
                if(stack[cursor-1] == '[')
                    cursor--;
                else if(stack[cursor-1] == '('){
                    isTrue = false;
                    break;
                }
            }
        }
    }
    if(isTrue && cursor==0){
        printf("yes\n");
    }
    else printf("no\n");
    
}

int main() {
    while(1){
        gets(str);
        if(strcmp(str,".") == 0) break;
        checkP(str);
    }
}