#include <iostream>
#define T_MAX 2000000001

using namespace std;

long long N,M;

long long t_max = T_MAX;

long long tree[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> tree[i];
    }
    
    long long start = 0;
    long long last = t_max;
    long long mid;

    while(last >= start){
        mid = (last+start)/2;
        long long len = 0;

        for(int i=0; i<N; i++){
            long long cut = tree[i] - mid;
            if(cut > 0)
                len += cut;
        }

        if(len >= M){
            start = mid +1;
        }
        else{
            last = mid -1;
        }
        // cout << "mid : " << mid << " start: " << start << " end : " << last << " len : " << len << '\n';

    }
    cout << last;
    
}