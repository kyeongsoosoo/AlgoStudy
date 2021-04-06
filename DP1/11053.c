#include <stdio.h>
#define max(a,b) (a>b ? a : b)

int arr[1000];
int DP[1000];
int highest=0;

int main() {
    int length;
    scanf("%d", &length);
    for(int i=0; i<length; i++){
        scanf("%d", arr+i);
    }
    for(int i=0; i<length; i++){
        DP[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j] <arr[i])
                DP[i] = max(DP[i], DP[j]+1);
        }
    }
    for(int i=0; i<length; i++){
        highest = max(highest, DP[i]);
    }
    printf("%d", highest);
    
}