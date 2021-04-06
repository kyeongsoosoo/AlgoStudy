#include <stdio.h>
#define MOD_N 1000000007



int N,K;

long long finder(long long num, long long idx){
    if(idx ==0) return 1;
    long long temp = finder(num, idx/2);
    if (idx%2) {
        return (temp * temp % MOD_N ) * num % MOD_N;
    }
    else
        return temp * temp % MOD_N;
}

int main() {
    scanf("%d %d", &N, &K);
    long long up=1, down=1, result;
    for (int i=2; i<= N; i++){
        up = (up*i) % MOD_N;
    }
    for( int i= 1;i<= N-K; i++){
        down = (down*i) %MOD_N;
    }
    for(int i=1; i<=K; i++){
        down = (down*i) % MOD_N;
    }
    result = (up * finder(down, MOD_N-2)) % MOD_N;
    printf("%lld", result);

}

