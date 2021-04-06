#include <stdio.h>
#include <string.h>

int main() {
    char word[101];
    gets(word);
    int length = strlen(word);
    int count = length;
    for(int i=1; i<=length; i++){
        if(word[i] == '='){
            if(word[i-1] == 'c' || word[i-1] == 's' || word[i-1] == 'z') count-=1;
            if(i>1 && word[i-1] =='z' && word[i-2]=='d' ) count -=1;
        }
        else if(word[i] == '-') {
            if(word[i-1] == 'c' || word[i-1] == 'd') count -=1;
        }
        else if(word[i] == 'j') {
            if(word[i-1] == 'l' || word[i-1] == 'n') count -= 1;
        }
    }
    printf("%d", count);
}