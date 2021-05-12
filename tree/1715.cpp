#include <iostream>
#include <math.h>
#include <cstring>
#define min(a,b) (a<b ? a : b)
#define max(a,b) (a>b ? a : b)

using namespace std;

int N;
int pq[100001];
int idx = 0;


void push(int n){
    pq[++idx] = n;
    int leaf_idx = idx;
    while(leaf_idx > 1){
        int p_idx = floor(leaf_idx/2);
        if(pq[p_idx] > pq[leaf_idx]){
            int temp = pq[p_idx];
            pq[p_idx] = pq[leaf_idx];
            pq[leaf_idx] = temp;
            leaf_idx = p_idx;
        }
        else{
            break;
        }

    }
}

int pop(){
    int result = pq[1];
    pq[1] = pq[idx--];
    int r_idx = 1;
    while(idx > 0 && r_idx*2  <= idx){
        int left = r_idx * 2;
        int left_n = pq[left];
        int min_n = min(left_n, pq[left+1]);
        //비교 최대한 줄이기
        int min_idx = left_n == min_n ? left : left+1;
        if(pq[r_idx] > min_n){
            pq[min_idx] = pq[r_idx];
            pq[r_idx] = min_n;
            r_idx = min_idx;
        }
        else{
            break;
        }
    }
    return result;
}


int main(){
    scanf("%d", &N);
    int card_n;
    memset(pq, 1001, sizeof(pq));
    for(int i=0; i<N; i++){
        scanf("%d", &card_n);
        push(card_n);
    }
    int result = 0;
    int sum = 0;

    while(idx != 1){
        int fir = pop();
        int sec = pop();
        result = fir+sec;
        sum += result;
        push(result);
    }

    printf("%d", sum);
}