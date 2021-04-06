#include <iostream>
#define max(a,b) (a>b ? a : b)

using namespace std;

int main() {
    int N;
    int DP[100000] = {0,};
    cin >> N;
    int *arr = new int[N];
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    DP[0] = arr[0];
    for(int i=1; i<N; i++){
         if(DP[i-1] < 0){
             DP[i] = arr[i];
         }
         else{
             DP[i] = DP[i-1] + arr[i];
         }
    }
    int maxN = DP[0];
    for(int i= 1; i<N; i++){
        maxN = max(maxN, DP[i]);
    }
    cout << maxN;
}