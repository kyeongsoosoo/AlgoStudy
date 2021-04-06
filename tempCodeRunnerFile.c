#include <stdio.h>
#include <string.h>

int main() {
    char first[3];
    char second[3];
    scanf("%s %s", first, second);
    for(int i=2; i>=0; i++){
        if(second[i]>first[i]){
            for(int j=2;j>=0;j--){
                printf("%c", second[j]);
            } break;
        }
        else if (second[i]<first[i]){
         for(int j=2;j>=0;j--){
                printf("%c", first[j]);
            } break;
        }
    }
    
}