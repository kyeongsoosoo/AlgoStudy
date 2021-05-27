#include <iostream>
#define MAX 1000000
#define H_MAX 2000000001

using namespace std;

int N;
int M;
int h[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> h[i];
    }

    long long start = 0;
    long long end = H_MAX;

    while(start <= end){
        long long mid = (start+end)/2;

        long long sum =0;

        for(int i=0; i<N; i++){
            long long cut =h[i] - mid;
            if(cut >0) 
                sum += cut;
        }

        // cout << start << " " << end << " "<< mid<< " " << sum << '\n';

        if(sum >= M){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        
    }

    cout << end;

}