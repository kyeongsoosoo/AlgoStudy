#include <stdio.h>
#define max(a,b) (a>b ? a : b)

int arr[100][2];
int DP[100];


void bubble_sort(int length) {
    int temp_x;
    int temp_y;
    for(int i=length-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(arr[j+1][0] < arr[j][0]){ 
                temp_x = arr[j+1][0];
                temp_y = arr[j+1][1];
                arr[j+1][0] = arr[j][0];
                arr[j+1][1] = arr[j][1];
                arr[j][0] = temp_x;
                arr[j][1] = temp_y;}
        }
    }
}

int main() {
    int lineN;
    int max_line = 0;
    scanf("%d", &lineN);
    for(int i=0; i<lineN; i++){
        scanf("%d %d", &arr[i][0],&arr[i][1]);
    }
    bubble_sort(lineN);
    for(int i=0; i<lineN; i++){
        DP[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j][1] < arr[i][1]){
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
    }
    for(int i=0; i<lineN; i++){
        if(DP[i] > max_line)
            max_line = DP[i];
    }
    printf("%d", lineN- max_line);
}