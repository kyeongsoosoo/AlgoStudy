#include <stdio.h>
#include <string.h>

int caseN;
int length;
int count = 0;
int isTrue = 0;
char p;
char PS[51];

int main() {
    scanf("%d", &caseN);
    for(int i=0; i< caseN; i++){
        scanf("%s", PS);
        count = 0;
        isTrue=1;
        length = strlen(PS);
        for(int i=0; i<length; i++){
            p = PS[i];
            if(p == '(') count++;
            else{
                if(count >0) count--;
                else {
                    isTrue=0;
                    break;
                }
            }
        }
        if(count==0 && isTrue) printf("YES\n");
        else printf("NO\n");
        

    }
}