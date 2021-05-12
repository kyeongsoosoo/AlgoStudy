#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int choo_N;
int choo_W[30];
int bid_N;
int bid_W[7];
int DP[31][15001];

void isAble(int count, int weight){
    if(count> choo_N || DP[count][weight] != -1)
        return;
    
    DP[count][weight] = 1;

    isAble(count+1, weight+choo_W[count]);
    isAble(count+1, weight);
    isAble(count+1, abs(weight-choo_W[count]));   
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> choo_N;
    for(int i=0; i<choo_N; i++){
        cin >> choo_W[i];
    }
    cin >> bid_N;
    for(int i=0; i<bid_N; i++){
        cin >> bid_W[i];
    }
    memset(DP, -1, sizeof(DP));
    isAble(0,0);
    for(int i=0; i<bid_N; i++){
        if(bid_W[i] > 15000)
            cout << "N ";
        else if(DP[choo_N][bid_W[i]] == 1)
            cout << "Y ";
        else 
            cout << "N ";
    }


}