#include <iostream>
#include <algorithm>
#define C_MAX 200000

using namespace std;

int N,C;
int cord[C_MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> C;
    for(int i=0; i< N; i++){
        cin >> cord[i];
    }

    sort(cord, cord+N);

    
    int start = 0;
    int last = cord[N-1];

    while(last >= start){
        int mid = (start+last) /2;
        
        int cnt = 1;
        int prev = cord[0];

        for(int i=1; i<N; i++){
            if(cord[i] - prev >= mid){
                cnt++;
                prev = cord[i];
            }
        }

        if(cnt >= C){
            start = mid +1;
        }
        else
            last = mid -1;
    }

    cout << last;

}