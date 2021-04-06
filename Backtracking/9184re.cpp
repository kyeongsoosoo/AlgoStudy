#include <iostream>

using namespace std;

int DP[21][21][21] = {{{0,},},};

int W(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    if( a > 20 || b > 20 || c > 20 ){
        return W(20,20,20);
    }
    if(DP[a][b][c])
        return DP[a][b][c];
    if(a < b && b < c)
        DP[a][b][c] = W(a,b,c-1) + W(a,b-1,c-1) - W(a,b-1,c);
    else
        DP[a][b][c] = W(a-1,b,c) +W(a-1,b-1,c)+ W(a-1, b, c-1) - W(a-1, b-1, c-1);
    return DP[a][b][c];
}

int main(){
    int a,b,c;
    while(1){
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1)
            break;
        printf("w(%d, %d, %d) = ",a,b,c);
        printf("%d\n",W(a,b,c));
    }
}