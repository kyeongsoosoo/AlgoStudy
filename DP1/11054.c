#include <stdio.h>
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)

int arr[1000];
int DP[1000];
int DP_R[1000];

int main() {
    int length;
    int max_n = 0;
    scanf("%d", &length);
    for(int i=0; i<length;i++){
        scanf("%d", arr+i);
    }
    for(int i=0; i<length; i++){
        DP[i] = 1;
        DP_R[length-i-1] = 1;
        for(int j = 0; j<i; j++){
            if(arr[j] < arr[i]){
                DP[i] = max(DP[i], DP[j] + 1);
            }
            if(arr[length - 1 -j] < arr[length - 1 - i]){
                DP_R[length - i -1] = max(DP_R[length - i -1], DP_R[length - j -1] + 1);
            }
        }
    }
    for(int i=0; i< length; i++){
        if(DP[i] + DP_R[i] > max_n)
            max_n = DP[i] + DP_R[i];
    }
    printf("%d", max_n-1);

}