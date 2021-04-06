#include <stdio.h>

int main() {
    int ex;
    scanf("%d", &ex);
    int count =0, index=666;
    int test,c;
    while(1) {
        test = index;
        c = 0;
        while(test > 500){
            if(test%10 == 6 && (test/10)%10 == 6 && (test/100)%10 == 6) c++;
            test /= 10;
            
        }
        if(c>= 1) count++;
        if(count == ex){
            printf("%d\n", index);
            break;
        }
        index++;
    }
}