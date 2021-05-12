#include <iostream>
#include <math.h>
#define abs(a) (a>= 0 ? a : a*(-1))
#define min(a,b) (a<b ? a : b)

using namespace std;

int heap[100000];
int idx = 0;

int pop_top() {
    if(idx == 0){
        return 0;
    }
    else{

        int result = heap[1];
        int r_idx = 1;
        heap[1] = heap[idx--];
        while( 2 * r_idx <= idx ){
            int l_idx = r_idx *2;
            int min_n = heap[l_idx];
            int right_idx;
            if( l_idx + 1 <= idx){
                right_idx = l_idx + 1;
                //두 수가 부호 상관없이 같은경우
                if(abs(heap[l_idx]) == abs(heap[right_idx]) ){
                    min_n = min(heap[l_idx], heap[right_idx]);
                }
                else{
                    int abs_min_n = min(abs(heap[l_idx]), abs(heap[right_idx]));
                    min_n = abs(heap[l_idx]) == abs_min_n ? heap[l_idx] : heap[right_idx];
                }
            }
            int min_idx = min_n == heap[l_idx] ? l_idx : right_idx;
            if(abs(heap[r_idx]) > abs(min_n)){
                int temp = heap[min_idx];
                heap[min_idx] = heap[r_idx];
                heap[r_idx] = temp;
                r_idx = min_idx;
            }
            else if(abs(heap[r_idx]) == abs(min_n)){
                if(heap[r_idx] > min_n){
                    int temp = heap[min_idx];
                    heap[min_idx] = heap[r_idx];
                    heap[r_idx] = temp;
                    r_idx = min_idx;
                }
                else 
                    break;
            }
            else {
                break;
            }
        }
        return result;
    }
}

void push(int c){
    heap[++idx] = c;
    int l_idx = idx;
    while( l_idx != 1){
        int p_idx = floor(l_idx/2);
        if(abs(heap[p_idx]) > abs(heap[l_idx])){
            int temp = heap[p_idx];
            heap[p_idx] = heap[l_idx];
            heap[l_idx] = temp;
            l_idx = p_idx;
        }
        else if(abs(heap[p_idx]) == abs(heap[l_idx])){
            if(heap[p_idx] >heap[l_idx]){
                int temp = heap[p_idx];
                heap[p_idx] = heap[l_idx];
                heap[l_idx] = temp;
                l_idx = p_idx;
            }
            else 
                break;
        }
        else{
            break;
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    scanf("%d", &N);
    int C;
    int res;

    for(int i=0; i<N; i++){
        scanf("%d", &C);
        if(C == 0){
            res = pop_top();
            printf("%d\n", res);
        }
        else{
            push(C);
        }
    }


}