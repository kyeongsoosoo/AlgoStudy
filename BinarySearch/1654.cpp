#include <iostream>
#include <algorithm>
#include <climits>
#define max(a,b) (a>b ? a : b)

using namespace std;

int K, N;

long long arr[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> K >> N;

    long long max_n = 0;

    for(int i=0; i<K; i++){
        cin >> arr[i];
        max_n = max(max_n, arr[i]);
    }

    long long start = 0;
    long long last = LLONG_MAX;

    while(last >= start){
        long long mid = (start+last) / 2;

        long long cnt = 0;

        for(int i=0; i<K; i++){
            cnt += arr[i] / mid;
        }

        if(cnt >= N)
            start = mid+1;
        else
            last = mid -1;
    }
    cout << last;

}