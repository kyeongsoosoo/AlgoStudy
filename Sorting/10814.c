#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    char name[101];
} User;

User list[100000];
int counter[100000];
User temp[100000];

int main() {
    int count;
    scanf("%d", &count);
    for(int i=0; i<count; i++){
        scanf("%d %s", &list[i].age, list[i].name);
        counter[list[i].age] += 1; 
    }
    for(int i=1; i<100000; i++){
        counter[i] += counter[i-1];
    }

    for(int i=count-1; i>=0; i--){
        temp[(counter[list[i].age]--)-1] = list[i];
    }

    for(int i=0; i<count; i++){
        printf("%d %s\n", temp[i].age, temp[i].name);
    }
}