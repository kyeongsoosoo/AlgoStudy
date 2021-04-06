#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


char word[51];
char num[6];

int main() {
    scanf("%s", word);
    int count = strlen(word);
    bool isSymbol, isPlus=true;;
    int index=0, result=0;
    int numIndex = 0;
   
    while(index<count){
        isSymbol = (word[index] == '+' || word[index] == '-');
        if(isSymbol){
            isPlus ? (result+= atoi(num)) : (result -= atoi(num));
             for(int i=0;i<6;i++){
        printf("%c\n", num[i]);
    }
            memset(num, 0, 6);
             for(int i=0;i<6;i++){
        printf("%c\n", num[i]);
    }
            numIndex = 0;
            if(word[index] == '-') isPlus = false;
        }
        else {
            num[numIndex++] = word[index];
        }
        index++;
    }
    isPlus ? (result+= atoi(num)) : (result -= atoi(num));
    printf("%d", result);
}