#include <stdio.h>

long long Stack[100000];
long long num;
int cursor = -1;
int caseN;
long long sum=0;

int main() {
    scanf("%d", &caseN);
    for(int i=0; i<caseN; i++){
        scanf("%lld", &num);
        if(!num) {
            cursor--;
        }
        else {
            Stack[++cursor] = num;
            }
    }
    
    for(int i=0; i<=cursor; i++){
        sum+= Stack[i];
    }
    printf("%lld\n", sum);
}