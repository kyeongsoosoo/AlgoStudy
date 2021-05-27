#include <iostream>
#include <algorithm>
#include <climits>
#define MAX 10001

using namespace std;

long long arr[MAX];

int N,K;

int searching(long long start, long long end){
    if(start > end) return end;
    long long mid = (start + end)/2;
    long long sum = 0;
    for(int i=0; i< K; i++){
        sum += arr[i]/mid;
    }
    if(sum >= N){
        return searching(mid+1,end);
    }
    else{
        return searching(start,mid-1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> N;

    int tmp;
    long long max_n = 0;
    for(int i=0; i<K; i++){
        cin >> arr[i];
        max_n = max(max_n, arr[i]);
    }

    long long ans =searching(0,LLONG_MAX);
    cout << ans;

}