#include <iostream>
#include <algorithm>


int W[10];
int K[10];

using namespace std;

bool compare(int a, int b){
    return a>b ? true : false;
}

int main(){
    int W_Sum =0;
    int K_Sum=0;
    for(int i=0; i<10; i++){
        cin >> W[i];
    }
    for(int i=0; i<10; i++){
        cin >> K[i];
    }
    sort(W,W+10, compare);
    sort(K,K+10,compare);
    for(int i = 0 ; i<3; i++){
        W_Sum += W[i];
        K_Sum += K[i];
    }
    cout << W_Sum << " "<< K_Sum;
    

}