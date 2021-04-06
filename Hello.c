#include <stdio.h>
#include <string.h>

int main(void) {
    char word[1000000];
    int alphabet[26]= {0,};
    int max_count[3]={0,};
    scanf("%s", word);
    int length = strlen(word);
    for(int j=65; j<91; j++){
        for(int i =0; i<length; i++){
            if(word[i] == j || word[i] == j+32){
                alphabet[j-65] += 1;
            }
        }
    }
    for(int i=0; i<26; i++){
        if(alphabet[i]>max_count[0]){
            max_count[0]=alphabet[i];
            max_count[1]=0;
            max_count[2]=i;
        }else if(alphabet[i]==max_count[0]){
            max_count[1]+=1;
        }
    }
    if(max_count[1]==0) printf("%c", max_count[2]+65);
    else printf("?");

}