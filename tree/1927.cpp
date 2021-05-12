#include <iostream>
#include <math.h>

using namespace std;

int heap[100000];
int idx = 0;


int print_top() {
    if(idx == 0)
        return 0;
    else {
        int res = heap[1];
        int r_idx = 1;
        heap[1] = heap[idx--];
        while( 2 * r_idx <= idx){
            int c_idx = 2 * r_idx;
            int left = c_idx;
            int right = -1;
            int min_n = heap[left];
            if(c_idx + 1 <= idx){
                right = c_idx +1;
                min_n= min(heap[left], heap[right]);
            }
            int min_idx = heap[left] == min_n ? left : right;
            if(min_n < heap[r_idx]){
                int temp = heap[r_idx];
                heap[r_idx] = min_n;
                heap[min_idx] = temp;
                r_idx = min_idx;
            }
            else{
                break;
            }
        }
        return res;
    }
}

void push(int c){
    heap[++idx] = c;
    int l_idx = idx;
    while(l_idx != 1){
        int p_idx = floor(l_idx/2);
        if(heap[l_idx] < heap[p_idx]){
            int temp = heap[p_idx];
            heap[p_idx] = heap[l_idx];
            heap[l_idx] = temp;
            l_idx = p_idx;
        }
        else{
            break;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int C;
    for(int i=0; i<N; i++){
        int res;
        cin >> C;
        if( C == 0){
            res = print_top();
            cout << res <<'\n';
        }
        else {
            push(C);
        }
    }    
}