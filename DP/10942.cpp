#include <iostream>

using namespace std;

int N;
int n_arr[2000];
int M;
int DP[2001][2001];

int findPal(int start, int end){

    if(start >= end) return 1;
    int &ref = DP[start][end];
    if(ref != -1) return ref;

    if(n_arr[start] == n_arr[end])
        return ref = findPal(start+1,end-1);
    else 
        return ref = 0;

    // if(DP[start][end] != -1)
    //     return DP[start][end];
    // if(end - start == 0){
    //     DP[start][end] = 1;    
    //     return 1;
    // } 
    // if(end - start == 1){
    //     if(n_arr[start] == n_arr[end])
    //         return DP[start][end] = 1;
    //     else 
    //         return DP[start][end] = 0;
    // }
    // else{
    //     if(n_arr[start] == n_arr[end]){
    //         return findPal(start+1, end-1);
    //     }
    //     else{
    //         return DP[start][end] = 0;
    //     }
    // }

}



int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &n_arr[i]);
        for (int j = 0; j < N; j++)
			DP[i][j] = -1;
    }
    scanf("%d", &M);
    int start, end;
    
    while(M--){
        scanf("%d %d", &start, &end);
        printf("%d\n", findPal(start-1,end-1));
        //start-1 과 end-1로 넣어줘야함.
    }
}