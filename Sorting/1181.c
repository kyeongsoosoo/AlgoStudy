#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char string[51];
    int length;
} str;

str word[20001];

void mergeSort(int start, int middle, int end){
    int s= start ,m = middle+1;
    int cursor = start;
    str temp[20001];
    while(s<=middle && m<=end) {
        if(word[s].length < word[m].length){
            temp[cursor++] = word[s++];
        }
        else if(word[s].length > word[m].length){
            temp[cursor++] = word[m++];
        }
        else{
            if(strcmp(word[s].string, word[m].string) < 0)
                 temp[cursor++] = word[s++];
            else temp[cursor++] = word[m++];
        }
    }
    while(s<=middle)
        temp[cursor++] = word[s++];
    while(m<=end)
         temp[cursor++] = word[m++];
    for(int i=start;i<=end;i++){
        word[i] = temp[i];
    }


}


void merge(int start, int end){
    if(start < end) {
        int middle = (start+end)/2;

        merge(start,middle);
        merge(middle+1, end);
        mergeSort(start,middle, end);
    }
}


int main() {
    int count;
    scanf("%d", &count);
    for(int i=0; i<count; i++){
        scanf("%s", word[i].string);
        word[i].length = strlen(word[i].string);
    }
    merge(0, count);
    for(int i=0;i<=count; i++){
        if(i>0 && strcmp(word[i].string, word[i-1].string) != 0)
            printf("%s\n", word[i].string);
    }
}