#include <stdio.h>
#include <string.h>

int main() {
    char N[11];
    gets(N);
    int tmp;
    for(int i=0; i< strlen(N)-1; i++ ){
        for(int j=i; j<strlen(N); j++){
            if(N[i] <N[j]) {
                tmp = N[i];
                N[i] = N[j];
                N[j] = tmp;
            }
        }
    }
    puts(N);

}