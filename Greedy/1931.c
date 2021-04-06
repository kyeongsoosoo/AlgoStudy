#include <stdio.h>

int time[100000][2];
int temp[100000][2];

void mergeSort(int start, int middle, int end){
    int s=start, m=middle+1, cursor=start;
    while(s<=middle && m<=end){
        if(time[s][1] > time[m][1]) {
            //2차원배열 한번에 할당
            temp[cursor][0] = time[m][0];
            temp[cursor++][1] = time[m++][1];
        }
        else if(time[s][1] < time[m][1]) {
            //2차원배열 한번에 할당
            temp[cursor][0] = time[s][0];
            temp[cursor++][1] = time[s++][1];
        }
        else {
            if(time[s][0] > time[m][0]){
                {
            //2차원배열 한번에 할당
            temp[cursor][0] = time[m][0];
            temp[cursor++][1] = time[m++][1];
        }
            }
            else{
                temp[cursor][0] = time[s][0];
                temp[cursor++][1] = time[s++][1];
            }
        }    
    }
    while(s<=middle){
        temp[cursor][0] = time[s][0];
         temp[cursor++][1] = time[s++][1];
    }
    while(m<=end){
        temp[cursor][0] = time[m][0];
         temp[cursor++][1] = time[m++][1];
    }
    for(int i=start;i<=end;i++){
        
        time[i][0] = temp[i][0];
        time[i][1] = temp[i][1];
    }
}

void merge(int start, int end){
    if(start<end){
        int middle=(start+end)/2;

        merge(start, middle);
        merge(middle+1, end);
        mergeSort(start, middle, end);
    }
}

int main() {
    int caseN, count=1;
    scanf("%d", &caseN);
    for(int i=0; i<caseN;i++){
        scanf("%d %d", &time[i][0], &time[i][1]);
    }
    merge(0,caseN-1);
    int start = time[0][0], end = time[0][1];
    for(int i =1;i<caseN;i++){
        if(end <= time[i][0]){
            end = time[i][1];
            count++;
        }
    }
    printf("%d", count);
    
}