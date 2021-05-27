#include <iostream>
#include <vector>
#define MAX 4000001

using namespace std;

int N;


int prime_set[MAX];

int prime[MAX];

void findPrime(){
    for(int i=2; i<=N; i++){
        prime_set[i] = i;
    }

    for(int i=2; i<=N; i++){
        if(prime_set[i] == 0) continue;
        for(int j = i*2; j<= N; j += i){
            prime_set[j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    findPrime();

    int from = 0;
    int to = 0;
    int len = 0;

    int idx = 0;

    for(int i=0; i<=N; i++){
        if(prime_set[i] != 0) {
            prime[idx++] = prime_set[i];
        }
    }
    int sum = prime[0];

    

    while(to < idx){
        if( sum < N){
            sum += prime[++to];
        }
        else if( sum == N){
            sum += prime[++to];
            len++;
        }
        else{
            sum -= prime[from++];
        }
    }

    cout << len;

}